#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e2 + 10;
/*
int finddist(int d, int s, int maxdist){
    int l = d, r = maxdist;
    while(maxdist-d>=1){
        int mid = (l+r)>>1;
        if((r-l)*2 >s ){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}*/
void solve(){
    int n;
    cin>>n;
    pair<int,int> traps[N];

    for(int i =  0; i<n; i++){
        cin>>traps[i].first>>traps[i].second;
    }
    sort(traps, traps+n);
    
    int maxdist = INT_MAX;
    for(int i =  0; i<n; i++){
        int d = traps[i].first, s = traps[i].second;
        
        int maxi = d + (int)((s-1)/2);
        
        maxdist = min(maxdist, maxi);
        /*if(d>=maxdist) continue;
        if((maxdist-d)*2 <= s) continue;
        
        maxdist = finddist(d,s,maxdist);*/
    }
    cout<<maxdist<<endl;   
    
    
}

int main(){
    int t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}