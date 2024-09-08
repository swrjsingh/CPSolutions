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
/*
int dp[1001];
int rec(int left, vector<int> &hprice, vector<int> &spages,int n){
    //Base case we run out of cash
    if(dp[left]!=-1) return dp[left];
    //if(left==0) return dp[left] = 1; //Base set in solve()
    //transition
    int ans = 0;
    for(int i = 0 ; i< n; i++){
        if(left>=hprice[i]){
            ans = max(rec(left-hprice[i],hprice,spages,n) + spages[i], ans);
        }
    }
    return dp[left] = ans;
    
    //rec returns the maximum pages you can get with that much cash

}

void solve() {
  int n,x;
  cin>>n>>x;
  vector<int> hprice(n);
  for(int i =  0; i<n; i++){
      cin>>hprice[i];
  }
  vector<int> spages(n);
  for(int i =  0; i<n; i++){
      cin>>spages[i];
  }
  for(int i =  0; i<x; i++){
      dp[i]=-1;
  }
  
  dp[0] = 0;
  
  cout<<rec(x,hprice,spages,n);

  


}
*/
int dp[1001];

void solve() {
  int n,x;
  cin>>n>>x;
  vector<int> hprice(n);
  vector<int> spages(n);
  for(int i =  0; i<n; i++){
      cin>>hprice[i];
  }
  for(int i =  0; i<n; i++){
      cin>>spages[i];
  }
  for(int i =  0; i<=x; i++){
      dp[i]=0;
  }
  
  for(int i=0; i<n; i++){
      for(int j=x; j>=hprice[i]; j--){
          dp[j] = max(dp[j], dp[j-hprice[i]] + spages[i]);
      }
  }
  
  cout<<dp[x]<<endl;
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
