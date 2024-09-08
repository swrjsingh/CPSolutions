#include<bits/stdc++.h>
using namespace std;
const int N = 510;
long long dist[N][N];

int main(){
/*     int n;
    cin>>n;
    //Take input of the weighted graph
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>dist[i][j];
        }
    }
    

    //Take input for which vertices got deleted
    vector<int> delvert(n);
    for(int i =  0; i<n; i++){
        cin>>delvert[i];
    }
    
    reverse(delvert.begin(),delvert.end());
    vector<long long> ans;
    
    for(int k = 0; k<n; k++){
        int k_v = delvert[k];
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                long long new_dist = dist[i][k_v] + dist[k_v][j];
                dist[i][j] = min(dist[i][j], new_dist);
            }
        }
        long long sum=0;
        for(int i = 0; i<=k; ++i){
            for(int j =  0; j<=k; j++){
                sum+=dist[delvert[i]][delvert[j]];
            }
            
        }
        ans.push_back(sum);
        
    }
    reverse(ans.begin(),ans.end());
    for(auto val : ans){
        cout<<val<<' ';
    }
    
     */

    int n;
    cin>>n;
    int dist[N][N];
    for(int i =  1; i<=n; i++){
        for(int j =  1; j<=n; j++){
            cin>>dist[i][j]; 
        }
    }
    
    
}