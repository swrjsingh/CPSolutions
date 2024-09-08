#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,w;
int weight[N], value[N];
long long dp[105][100005];

long long func(int index, int remaining){
    if(remaining == 0) return 0;
    if(index < 0) return 0;
    if(dp[index][remaining]!=-1) return dp[index][remaining];
    long long ans = func(index - 1, remaining);//not choosing the item
    if(remaining - weight[index] >=0 )
    ans = max(ans, func(index - 1, remaining - weight[index]) + value[index]);//choosing the item
    return dp[index][remaining]=ans;
    //dp returns the maximum possible value that you can get from a certain 
    //type of 

}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    for(int i = 0; i<n; i++){
        cin>>weight[i]>>value[i];
    }
    cout<<func(n-1,w);
}