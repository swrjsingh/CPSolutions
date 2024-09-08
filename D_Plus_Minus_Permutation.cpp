#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
void solve(){

    ll n,x,y;
    cin>>n>>x>>y;
    if(x==y){
        cout<<0<<endl;
        return;
    }
    
    ll addn = (ll)(n/x);
    ll subn = (ll)(n/y);
    ll cmmn = (ll)(x*y/__gcd(x,y));
    cmmn = (ll)(n/cmmn);
    //deb2(addn,subn);
    //deb(cmmn);
    addn = addn-cmmn;
    subn = subn-cmmn;
    //deb2(addn,subn);
    ll sumx = ((n)*(n+1))/2 - ((n-addn)*(n-addn+1))/2;
    ll sumy = ((subn)*(subn+1))/2;
    //deb2(sumx,sumy);
    cout<<sumx-sumy<<endl;

}
int main(){
    ll t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}


