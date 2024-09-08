#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;



int main(){
    ll a[3], r, g, b, ans;
    for(int i =  0; i<3; i++){
        cin>>a[i];
    }
    sort(a,a+3);
    ans = min(a[0]+a[1], (a[0]+a[1]+a[2])/3);

    cout<<ans<<endl;
}