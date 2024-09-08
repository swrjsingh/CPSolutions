#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;

int main(){
    ll n,k,ans=-1;
    cin>>n>>k;
    ll l=0,r=k-1;
    while(l<=r){
        long m = (l+r)/2;
        long sum = ((m)*(2*k-m-1))/2;

        if(n-1<=sum){
            ans =m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans;
}