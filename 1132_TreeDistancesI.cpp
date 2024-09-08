#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
int max1[N], max2[N],c[N];

//Calculate max path within subtrees rooted at i
//dfs for finding height of each node
void dfs1(int v, int p = -1){
    max1[v]=0, max2[v]=0;
    for(int u : g[v]){

        if(u==p) continue;
        
        dfs1(u,v);
        if(max1[u]+1>max1[v]){ //if max length from child is more than max length from node
            max2[v]=max1[v];//current max length becomes 2nd max
            max1[v]=max1[u]+1;//and we have a new curr max length
            c[v]=u;//max length pass goes through neighbour u
        }
        else if(max1[u]+1>max2[v]){//if its larger than second, but not largest
            max2[v] = max1[u]+1;//we have new second largest
        }
    }
    
}

//calculate max path outside subtrees rooted at i
void dfs2(int v, int p = -1){
    
    for(int u : g[v]){

        if(u==p) continue;
        if(c[v]==u){//if largest path passes through this child
            if(max1[u]<max2[v]+1){//if child's largest is less than your second largest
                //implies we have longer path if we go through current node 
                max2[u]=max1[u];//so we update the max1 and max2 of child
                max1[u] = max2[v]+1;
                c[u] = v;
            } 
            else{
                max2[u] = max(max2[u],max2[v]+1);

            }
        }
        else { //if largest path is not through child
            //then we have a larger path for child that passes through current node 
            max2[u] = max(max2[u],max1[u]);
            max1[u] = max2[v]+1;
            c[u]=v;
        }
        dfs2(u,v);
    }
    
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
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i = 1; i<=n; i++){
        cout<<max1[i]<<" ";
    }
    
    
}
