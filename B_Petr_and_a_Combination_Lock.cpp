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
combo : turn : 
0 -10 -20 -30 = -60
1 +10 -20 -30 = -40
2 +10 +20 -30 = 0 (yes) 
3
4
5
6
7
8




*/
void solve() {
  int i=0, j, n, m,flag=0;
  cin>>n;
  vector<int> sequence(n);
  for(int i =  0; i<n; i++){
      cin>>sequence[i];
  }
  int posscombos = 1<<n;//possible combos, for n = 3 => 2^3 = 8 = 1000
  for(int combo = 0; combo<posscombos; combo++){// combo = 0,1,2..7
    int sum = 0;
    for(int turn =  0; turn<n; turn++){// iterate through the sequence
        //j = 1<<turn;
        //m = combo&j;
        //cout<<"combo = "<<combo<<" turn = "<<turn<<" 1<<turn = "<<j<<" combo & (1<<turn) = "<<m;
        if(combo & (1<<turn))sum += sequence[turn];// if in that combo, 
        //that specific turn is yes then go clockwise and add, 
        //else subtract as anticlockwise
        else sum-=sequence[turn];
        //cout<<sequence[turn]<<endl;
        //cout<<" sum = "<<sum<<"\n";
        
    }
    if(sum%360==0){
      flag = 1;
      //cout<<"\n SUM = 0 NOW\n";
      break;
    }
  }
  if(flag==1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;

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
