#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 110;
int n;
int a[100004];
int dp[100004];
int func(int ind){
    if(ind > n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int count = 0;
    for(int i = 2*ind;i<=n;i+=ind){
        if(a[i]>a[ind]){ count = max(count, 1+func(i));}
    }
    return dp[ind] = count;
}
void solve(){
    
    int maxi = 1;
    cin>>n;
    for(int i =  1; i<=n; i++){
        cin>>a[i];
        dp[i]=-1;
    }
    //memset(dp, -1, sizeof(dp));
    for(int i =  1; i<=n; i++){
        maxi = max(maxi, 1+func(i));
    }
    cout<<maxi<<endl;

    
    
}
int main(){
    int t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}