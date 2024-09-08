#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;
int B,S,C,nb,nc,ns,pb,pc,ps;
long long r;
long long fb,fs,fc;

long long price(long long x){ //if he makes x hamburgers, how many rubles does it cost him?
    fb = max(x*B-nb,(ll)0); 
    fs = max(x*S-ns,(ll)0);
    fc = max(x*C-nc,(ll)0);

    long long p = fb*pb + fc*pc + fs*ps;
    return p;// p is the price paid to make x hamburgers

}


int main(){
    string ham;
    cin>>ham;//what's the recipe
    B=0;S=0;C=0;
    for(char c : ham){
        if (c=='B') B+=1;
        if (c=='C') C+=1;
        if(c=='S') S+=1;
    }

    cin>>nb>>ns>>nc;//how many are there in the kitchen
    cin>>pb>>ps>>pc;//price of each
    cin>>r;//how much money he has

    //we're doing binary search on how many he can make
    //r+1000 will always be larger than our answer since 
    //each hamburger has at least one of BSC, and each BSC costs at least one, r/3 is the lowest extra he can make
    ll high, low, mid, z, ans = 0;
    low = 0; high = r + 1000, mid = 0;
    while(low<=high){
        mid = (low + high)/2;
        z = price(mid);
        if(z==r){//ie he uses up all his money
            cout<<mid<<endl;
            return 0;
        }
        if(z>r){//he doesn't have enough money to make those many
            high = mid-1;
        }
        else{
            low = mid+1, ans = mid;//he still has money left
        }
    }
    cout<<ans<<endl;

}



