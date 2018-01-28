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
int coindp(int coins[],int amount,int n){
    int * dp=new int[amount+1];
    for(int i=0;i<=amount;i++){
        dp[i]=INT_MAX;
    }



    dp[0]=0;
    for(int i=1;i<=amount;i++){

        for(int j=0;j<n;j++){
            if(coins[j]<=i){
                int small=dp[i-coins[j]];
                if(small!=INT_MAX){
                    dp[i]=min(dp[i],small+1);
                }
            }
        }


    }
    return dp[amount];
}
int knapsack(int wts[],int prices[],int W,int N){
    if(W<=0 || N<=0){
        return 0;
    }
    int inc=0;int exc=0;

    if(wts[N-1]<=W){
        inc=prices[N-1]+knapsack(wts,prices,W-wts[N-1],N-1);
    }
    exc=0+knapsack(wts,prices,W,N-1);
    return max(inc,exc);
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
    int ind_coins[]={1,2,5,10};
//    cout<<fibb(n)<<endl;
//    cout<<fibdp(k,dp)<<endl;
//    cout<<bottomdp(n)<<endl;
    //cout<<ladderrec(n,3)<<endl;
    //cout<<laddertopdown(n,dp)<<endl;
//    cout<<coinsneeded(coins,15,3)<<endl;
//    cout<<coindp(ind_coins,39,4);
    int wts[]={2,7,3,4};
    int prices[]={5,20,20,10};
    int W=11;
    int N=4;
    cout<<knapsack(wts,prices,W,N);
    return 0;
}