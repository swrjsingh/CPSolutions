#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N],b[N],c[N];
int n;
int dp[N][4];
int solve(int i, int prev){ // function returns the maximum ans on the ith day, it needs the day i and the activity of the previous day
    if(i==n) return 0;
    int ans = INT_MIN;
    if(dp[i][prev]!=-1) return dp[i][prev];
    if(prev==0){
        ans = max(ans, b[i]+solve(i+1,1));
        ans = max(ans, c[i]+solve(i+1,2));
    }
    else if(prev==1){
        ans = max(ans, a[i]+solve(i+1,0));
        ans = max(ans, c[i]+solve(i+1,2));
    }
    else if(prev==2){
        ans = max(ans, b[i]+solve(i+1,1));
        ans = max(ans, a[i]+solve(i+1,0));
    }
    else{ //if vs else if was causing the difference
        ans = max(ans, a[i]+solve(i+1,0));
        ans = max(ans, b[i]+solve(i+1,1));
        ans = max(ans, c[i]+solve(i+1,2));
    }
    return dp[i][prev] = ans;
    //cout<<"ans = "<<ans<<"; i = "<<i<<"; prev = "<<prev<<endl;
    return ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    int ans = solve(0,3);
    cout<<ans<<endl;
    /*
    for(int i = 0; i<n; i++){
        for(int j = 0; j<4; j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }*/
}
