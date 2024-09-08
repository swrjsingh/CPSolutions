#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 3e5 + 10;



vector<int> g[N];
int dp[N][2];
int par[N];//par and p represent parents array and parent

void dfs(int v, int p = -1){
    
    for(int u : g[v]){

        if(u==p) continue;
        
        dfs(u,v);
        dp[v][0] =dp[v][0] + max(dp[u][0],dp[u][1]);
    }
    for(int u: g[v]){
        if(u==p) continue;
        dp[v][1] = max(dp[v][1], dp[u][0] + 1 + dp[v][0] - max(dp[u][0], dp[u][1]));
    }
    
}

int main(){
    int n, m;//number of vertices, number of edges
    cin>>n;
    int v1,v2;
    for(int i = 1; i<n; i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1,-1);
    cout<<max(dp[1][0],dp[1][1]);

}


