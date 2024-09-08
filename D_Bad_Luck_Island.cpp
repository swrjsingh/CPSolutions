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
double dp[102][102][102];

double rock(int r, int s, int p){
    if(p==0) return 1.0; //rock will survive always
    if(r==0 || s==0) return 0.0; //rock will not survive
    if(dp[r][s][p]>-0.5){ //
        return dp[r][s][p];
    }

    double total = (r*s + s*p + p*r) * 1.0; //total number of matches possible
    double ans = 0.0;

    ans += rock(r,s,p-1) * (1.0 * (s*p) / (total));//probability that rock fights
    ans += rock(r,s-1,p) * (1.0 * (s*r) / (total));
    ans += rock(r-1,s,p) * (1.0 * (r*p) / (total));
    return dp[r][s][p] = ans;

}

double scissor(int r, int s, int p){
    if(r==0) return 1.0; //rock will survive always
    if(p==0 || s==0) return 0.0; //rock will not survive
    if(dp[r][s][p]>-0.5){ //
        return dp[r][s][p];
    }

    double total = (r*s + s*p + p*r) * 1.0; //total number of matches possible
    double ans = 0.0;

    ans += scissor(r,s,p-1) * (1.0 * (s*p) / (total));//probability that rock fights
    ans += scissor(r,s-1,p) * (1.0 * (s*r) / (total));
    ans += scissor(r-1,s,p) * (1.0 * (r*p) / (total));
    return dp[r][s][p] = ans;
}

double paper(int r, int s, int p){
    if(s==0) return 1.0; //rock will survive always
    if(r==0 || p==0) return 0.0; //rock will not survive
    if(dp[r][s][p]>-0.5){ //
        return dp[r][s][p];
    }

    double total = (r*s + s*p + p*r) * 1.0; //total number of matches possible
    double ans = 0.0;

    ans += paper(r,s,p-1) * (1.0 * (s*p) / (total));//probability that rock fights
    ans += paper(r,s-1,p) * (1.0 * (s*r) / (total));
    ans += paper(r-1,s,p) * (1.0 * (r*p) / (total));
    return dp[r][s][p] = ans;
}

void solve() {
  int i, j, n, m;
  int r,p,s;
  cin>>r>>s>>p;
    memset(dp,-1.0, sizeof dp);
    cout<< fixed << setprecision(10) <<rock(r,s,p)<< " ";
    memset(dp,-1.0, sizeof dp);
    cout<< fixed << setprecision(10) <<scissor(r,s,p)<< " ";
    memset(dp,-1.0, sizeof dp);
    cout<< fixed << setprecision(10) <<paper(r,s,p)<< "\n";
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
