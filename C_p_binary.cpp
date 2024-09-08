#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
  uniform_int_distribution<int> uid(0,lim-1);
  return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

int countBits(int n){
  int cnt = 0;
  while(n>0){
    cnt+= (n&1);
    n>>1;
  }
  return cnt;
}

void solve() {
  ll n,p;
  cin>>n>>p;
  ll ans=INT_MAX;
  for(int i=0;i<=31;i++){ 
    /*the smallest possible number of summands required to represent n would be equal to the 
    number of bits needed to represent n(that is, worst case scenario is number of bits of n where all are 1
    Since 10^9 can be represented using approximately     30 bits, the loop limit of 31 ensures that we 
    consider all possible valid representations.
   */ 
  
      ll temp=n-i*p; //for each summand, we have a p, so we need to get the powers of 2 to add up to n - i*p;
      //now we solve the problem for this temp (remaining) value;
      if(__builtin_popcount(temp)<=i && temp>0){//we find number of set bits in binary representaiton of temp, it must be lesser than our i, and whether temp is > 0
        multiset<ll> m;//we store the powers of 2 that are needed in n, that is the set bits in the binary representaiton of n
        
        
        for(ll j=31;j>=0;j--){ //we go through all the bits in the 31 available slots
           if((temp>>j)&1){// if the jth bit of temp is set (j goes from last bit (31st) to the 0th bit(smallest))
            m.insert(1ll<<j);//then we insert that power of 2 in our multiset
           }
        }


        //if(m.size()>i){break;} // if multiset size is more than i, that means we can't represent it with i summands (current i)
        
        if(m.size()<=i){ // if m.size is lesser than or equal to i
          bool t=1; //just to represent that we've entered this loop
          while(m.size()!=i){//if m size is lesser than i
            auto it=*m.rbegin(); //we put our iterator at the last value (rbegin does that), which is the
            //largest power of 2, and then dereferencing it gives us that value
            
            if(it==1)t=0; //we remove the largest power of 2, and add its half twice to the multiset, 
            m.erase(--m.end());//this way we are increasing the number of elements in our multiset by 1
            m.insert(it/2);
            m.insert(it/2);
          }
          if(t){ //if we had entered this loop, we print the value of i for which it works
            cout<<i<<" ";
            return;
         }
        }//
      }
  }
  
  cout<<-1<<"\n";  


}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
  int i, u, v;
  while(m--){
    cin>>u>>v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par){
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}
