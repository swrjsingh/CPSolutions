#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
void solve(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i =  0; i<n; i++){
        int x;
        cin>>x;
        if(i && a.back() > x){
            a.push_back(1);
        }
        a.push_back(x);
    }
    cout<<a.size()<<endl;
    for(int x : a){
        cout<<x<<" ";
    }
    cout<<endl;
    



    
}
int main(){
    int t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}