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

void solve() {
  int i, j, n, m;
  cin>>n;
  vector<int> arr(n);
  for(int i =  0; i<n; i++){
      cin>>arr[i];
  }
  vector<int> res(33);//to store all the set bits from all numbers
  for(int j =  0; j<32; j++){  //from 0 to 31 to store all the bits (number can't be more than 2^31) 
    for(int i =  0; i<n; i++){//iterating through the elements)
        if(arr[i] & (1<<j)) res[j]++;//if the bits are already set, the increment our counter for that k
        //for that particular bit position
        //if counter becomes a multiple of our chosen k, that means we can use that k (from 1 to n, so i is the k)
    }
  }
  vector<int>ans;
  for(int k = 1; k<n+1; k++){ //go through all the possible k values
      bool ok = true;
      for(int j =  0; j<32; j++){
          if(res[j]%k != 0) {ok = false; break;} //check if counter of ALL BITS is multiple of k

      }
      if(ok) ans.push_back(k);//if ALL BITS counter is multiple of k then we can use that k value
    }
  sort(ans.begin(), ans.end());
  for(int i =  0; i<ans.size(); i++){
      cout<<ans[i]<<" ";
  }
  cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
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
