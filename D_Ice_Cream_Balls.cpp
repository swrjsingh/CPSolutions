#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n;
    cin>>n;
    int l = 0, r = min<int>(2e9, 2*n);
    while(r-l>1){
        int m = (l+r)>>1;
        if(m*(m-1)/2 + m < n){
            l=m;
        }
        else{
            r=m;
        }
    }
    int y = n - (r * (r-1) / 2);
    if((r+1)*r / 2 <=n){
        cout<<min(r+y, r+1+n - (r+1) * r/2) << endl;
    }
    else{
        cout<<r+y<<endl;
    }

}
int main(){
    int t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}