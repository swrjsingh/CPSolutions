#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
vector<pair<int,int>> cost[N];
int vis[N], par[N], dist[N], N, E;
bool dijkstra(int st, int en){
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;
    for(int i = 1; i<=N; i++){
        dist[i] = INFINITY;
    }
    pq.push(pair<int,int>(0,st));
    par[st] = -1;
    dist[st] = 0;
    while(!pq.empty()){
        int h = pq.top().second();
        pq.pop();
        if(h==en){
            return true;
        }
        vis[h] = 1;
        for(auto i: cost[h]){
            int w = i.second, v = i.first;
            if(!vis[v]&& dist[h]+w<dist[v]){
                dist[v] = dist[h]+w;
                pq.push(pair<int,int>(dist[v],w));
            }
        }

    }
    return false;
}

void f(ll i){
    if(i!=1) f
}

int main(){
    
    vector<int> g[N];
    int n, m;//number of vertices, number of edges
    cin>>n>>m;
    int v1,v2;
    for(int i = 0; i<m; i++){
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
}