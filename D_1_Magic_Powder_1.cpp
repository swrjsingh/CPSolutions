#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e3 + 10;
int n,k;
int ing[N];
int has[N];
long long price(int mid){
    ll cost = 0;
    for(int i =  0; i<n; i++){
        cost+=max(mid*ing[i]-has[i],0);
    }
    return cost;
    
}

int main(){

    cin>>n>>k;

    for(int i =  0; i<n; i++){
        cin>>ing[i];
    }

    for(int i =  0; i<n; i++){
        cin>>has[i];
    }
    int ans = 0;
    int high = 1e6, low = 0;
    while(low<=high){
        int mid = (high+low)/2;
        long long z = price(mid);
        if(z==k){
            cout<<mid;
            return 0;
        }
        if(z>k){
            high = mid-1;
        }
        else{
            low = mid+1;
            ans = mid;
        }
    }
    cout<<ans;
}