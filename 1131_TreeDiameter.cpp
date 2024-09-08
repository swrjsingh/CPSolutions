#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int heightarr[N];

int height(int v, int p){
    int ans = 0;
    for(auto u : g[v]){
        if(u==p) continue;
        ans = max(ans, height(u,v)+1);
    }
    return heightarr[v] = ans;

}
int dfs(int v, int p = -1){
    //if the vertex is not end vertex of largest path
    //largest path is just sum of heights of its sub branches + 2
    int ans = 0, i = 0;
    priority_queue<int> nd;

    for(int u : g[v]){
        if(u==p) continue;
        nd.push(heightarr[u]+1);
    }
    while(!nd.empty() && i<2){
        ans+=nd.top(); nd.pop(); i++;
    }

    for(int u : g[v]){
        if(u==p) continue;
        ans = max(ans, dfs(u,v));
    }
    return ans;    
}
int main(){

    int n;//number of vertices, number of edges
    cin>>n;
    
    int v1,v2;
    for(int i = 1; i<n; i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    height(1,-1);
    cout<<dfs(1,-1);
    
}
