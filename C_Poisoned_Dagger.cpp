#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int n;
ll h;
int attack[110];
ll damagedone(ll k){
    ll damage = 0;
    for(int i =  0; i<n-1; i++){
        damage+=min(k,((ll)1)*(attack[i+1]-attack[i]));
        //deb2(i,n);
        //deb(damage);
    }
    damage+=k;
    //deb(damage);
    return damage;
    
}
void solve(){
    cin>>n>>h;
    for(int i =  0; i<n; i++){
        cin>>attack[i];
    }
    ll low = 0, high = h+1, ans = 0;
    while(low<=high){
        //deb2(high,low);
        ll mid = (low+high)/2;
        //deb(mid);
        ll z = damagedone(mid);
        //deb(z);
        if(z == h){
            //cout<<"z==h, printing mid"<<endl;
            cout<<mid<<endl;
            return;
        }
        if(z<h){
            //cout<<"z<h, setting low = mid + 1"<<endl;
            low = mid+1;
        }
        else{
            //cout<<"z>h, setting ans = mid and low = mid - 1"<<endl;
            ans = mid;
            high = mid-1;
        }

    }
    cout<<ans<<endl;


    
}
int main(){
    int t;
    cin>>t;//t test cases
    while(t--){
        solve();
    }
}
