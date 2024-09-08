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

const int N = 1e5+5;
vector<int> g[N];
long long a[N]; // Changed to long long if needed based on problem constraints

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), diff(n + 1, 0); // Changed to long long
    for (long long &ae : a) cin >> ae; // Changed to long long
    vector<vector<int>> operations(m, vector<int>(3));
    for (auto &op : operations) cin >> op[0] >> op[1] >> op[2];

    // Initialize a vector to count the number of times each operation is applied
    vector<int> opCount(m + 1, 0);
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        // Increment the start of the range and decrement the end+1 to use prefix sum later
        opCount[x - 1] += 1;
        opCount[y] -= 1;
    }

    // Apply prefix sum on opCount to find the actual count for each operation
    for (int i = 1; i < m; i++) {
        opCount[i] += opCount[i - 1];
    }

    // Apply each operation according to its count to the difference array
    for (int i = 0; i < m; i++) {
        int l = operations[i][0] - 1; // Adjusting for 0-based indexing
        int r = operations[i][1]; // No adjustment needed for exclusive end
        long long d = operations[i][2]; // Changed to long long
        diff[l] += d * opCount[i];
        diff[r] -= d * opCount[i];
    }

    // Apply prefix sum on the difference array to get the final values
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }

    // Add the initial array values to the difference array to get the final result
    for (int i = 0; i < n; i++) {
        a[i] += diff[i];
        cout << a[i] << " ";
    }
    cout << "\n";
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