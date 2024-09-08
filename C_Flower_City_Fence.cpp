#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 2e5 + 10;

void solve(){
    int n;
    cin>>n;
    vector<int> fence(n+1);
    for(int i =  1; i<=n; i++){
        cin>>fence[i];
    }
    if(fence[1]!=n){
        cout<<"NO"<<endl;
        return;
    }
    vector<int> horizontal;
    for(int i =  n; i>=1; i--){
        while(horizontal.size()<fence[i]){
            horizontal.push_back(i);
        }
    }
    bool same = true;
    for(int i =  1; i<=n; i++){
        if(fence[i]!=horizontal[i-1]){
            cout<<"NO"<<endl;
            same = false;
            return;
        }
    }
    if(same){
        cout<<"YES"<<endl;
    }
}

int main(){
    int t;
    cin>>t;//t test cases
    //deb(t);
    while(t--){
        //deb(t);
        solve();
    }

}