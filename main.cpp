#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int fibb(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibb(n-1) + fibb(n-2);
}

int fibdp(int n,int * dp){
    if(n==0 || n==1){
        dp[n]=n;
        return n;
    }
    if(dp[n]!= -1){
        return dp[n];
    }
    else{
        dp[n]=fibdp(n-1,dp) + fibdp(n-2,dp);
        return dp[n];
    }
}
int bottomdp(int n){
    int * dp=new int[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];

    }
    return dp[n];
}

int ladderrec(int n,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
int ans=0;
   for(int j=1;j<=k;j++){
    ans += ladderrec(n-j,k);
   }
    return ans;
}

int laddertopdown(int n,int * dp){
    if(n==0){
        dp[n]=1;
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!= -1){
        return dp[n];
    }
        else{
        dp[n]=dp[n-1]+dp[n-2]+dp[n-3];
        return dp[n];
    }

}

int coinsneeded(int coins[],int amount,int n){
    if(amount==0){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(amount-coins[i]>=0){
            int small=coinsneeded(coins,amount-coins[i],n);
            if(small!=INT_MAX){
                ans=min(ans,small+1);
            }
        }
    }
    return ans;
}


int main() {
    int n;
    cin>>n;
    int k=n;
    int dp[100];
    for(int i=0;i<100;i++){
        dp[i]=-1;
    }
    int coins[]={1,7,10};
//    cout<<fibb(n)<<endl;
//    cout<<fibdp(k,dp)<<endl;
//    cout<<bottomdp(n)<<endl;
    cout<<ladderrec(n,3)<<endl;
    //cout<<laddertopdown(n,dp)<<endl;
    cout<<coinsneeded(coins,15,3)<<endl;
    return 0;
}