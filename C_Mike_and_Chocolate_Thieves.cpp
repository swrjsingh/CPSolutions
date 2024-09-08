#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;


ll can(ll cap){
    ll ret = 0;
    for(ll k = 2; k*k*k<=cap;k++){
        ret+=(cap/(k*k*k));
    }
    return ret;
}


int main(){
    ll n;
    cin>>n;
    ll low = 0, high = 1e18;
    ll ans = -1;
    while(low<=high){
        ll mid = low +(high - low)/2;
        ll ret = can(mid);
        if(ret == n) ans = mid;
        if(ret>=n) high = mid - 1;
        else low = mid + 1;
    }
    cout << ans;
    return 0;


    /*
    1 (8,27,64,125..3 n^3)
    2 (16,54,...)
    3 (24, 81...)
    n^3
    2n^3
    3n^3
    4n^3
    5n^3
    
    
    */
}