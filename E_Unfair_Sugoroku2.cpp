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
int mpow(int base, int exp, int mod); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int N = 3e5, M = N;
int mod = 998244353; // Use mod consistently for modulus operations

vi g[N];
int a[N];

ll bin_exp(ll a, ll x, ll mod){
    if(x==0) return 1;
    ll ans = bin_exp(a,x/2, mod);
    ans = (ans*ans)%mod;
    return (x%2) ? (ans*a) % mod : ans;
}
ll mulinv(ll a, ll mod){
    return bin_exp(a, mod-2, mod);
}
void solve() {
    int n,a,b,p,q;
    cin>>n>>a>>b>>p>>q;
    int dp1[n+1][n+1], dp2[n+1][n+1];
    int invp = mulinv(p, mod), invq = mulinv(q, mod);
    //dp[i][j] stores probability of getting a score of j in first i moves
    //at max you need n moves to get n, since you can start at 0 and get a 1 every single time
    // so i happens n times, from 0 to n-1
    for(int i =  0; i<n; i++){
        for(int j =  0; j<n; j++){
            dp2[i][j] = dp1[i][j] = 0;
        }
    }
    //We want to reach sum of n-a, not n, so that we can set standard base case
    //Base case, dp[0][0] = 1, since at 0th step you def have a sum of 0
    //dp[0][j] is 0 since at 0th move you can't have any sum 
    dp1[0][0] = dp2[0][0] = 1;   
    for(int j =  0; j<n; j++){
        dp2[0][j] = dp1[0][j] = (j==0);
    }
    


    for(ll i =  0; i<n; i++){
        for(ll j =  0; j<n; j++){
            for(ll k = 1; k<=max(p,q); k++){
                //for all possible values at each
                //increment the next step probability
                //next step = next step + 1/p or 1/q

                if(k<=p) dp1[i+1][min(n-a, j+k)] = (dp1[i+1][min(n-a,j+k)]+dp1[i][j]*invp)%mod;
                if(k<=q) dp2[i+1][min(n-b, j+k)] = (dp2[i+1][min(n-b,j+k)]+dp2[i][j]*invq)%mod;
            }
            
        }

    }
    ll ans = 0;
    for(int i=1; i<=n; i++){
        ll x = dp1[i][n-a]; //probability of reach required sum (n-a) in i steps
        ll y = 0;
        for(int j = 0; j<n-b; j++){
            y = (y+dp2[i-1][j])%mod; // so all the values of j that are lesser
        }

        ans = (ans + (x*y) %mod)%mod; // that probability of x * probability of y is the total prob that takahashi wins at ith step

    }
    cout<<ans<<endl;

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

int mpow(int base, int exp, int mod) {
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
