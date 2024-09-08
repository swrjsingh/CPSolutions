#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n;
long long w;
int value[N];
long long weight[N];
long long dp[N][100005];

long long func(int i, int valueleft){//returns minimum weight to make a value
    if(valueleft == 0) return 0;//base condition #1
    if(i < 0) return 1e15;//base condition #2
    if(dp[i][valueleft]!=-1) return dp[i][valueleft];//
    long long ans = INT_MAX;//
    ans = min(ans, func(i-1, valueleft));//didn't choose
    if(valueleft-value[i]>=0)//
    ans = min(ans, func(i-1, valueleft-value[i])+weight[i]);//
    return dp[i][valueleft] = ans;//
}


int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    for(int i = 0; i<n; i++){
        cin>>weight[i]>>value[i];
    }
    int maxvalue = 1e5;
    for(int i = maxvalue; i>=0;i--){
        if(func(n-1,i) <=w){
            cout<<i<<endl;
            break;
        }
    }
}
