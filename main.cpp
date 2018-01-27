#include <iostream>
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


int main() {
    int n;
    cin>>n;
    int k=n;
    int dp[100];
    for(int i=0;i<100;i++){
        dp[i]=-1;
    }
//    cout<<fibb(n)<<endl;
//    cout<<fibdp(k,dp)<<endl;
//    cout<<bottomdp(n)<<endl;
    return 0;
}