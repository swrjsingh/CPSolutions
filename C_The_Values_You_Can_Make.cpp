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
  int i, j, n, m,k;
  cin>>n>>k;
  int coins[n];//there are n coins
  for(int i =  0; i<n; i++){
      cin>>coins[i];// what are the n coins
  }
  bool dp[n+1][k+1][k+1];

  /*
  dp[i][j][y] represents if its possible to make a sum of j using the first i coins
  such that a subset of this subset has the sum y
  
  3 loops are used to iterate over all coins, all possible sums using these coins that are lesser than the given sum
  and all possible subset sums within those sums
  Here's why the loop is needed:

Ensuring All Possible Subsets are Considered:

For each coin val, we need to consider whether including it in a subset will lead to a sum equal to k. 
This includes considering subsets where the sum is less than k but might be part of a larger subset that sums to k.
Updating DP States:

By considering all possible sums j, the algorithm can correctly update the DP array to reflect whether 
 subset of coins with sum j could potentially lead to a subset with sum k. This is essential for 
 determining all suitable values x that Arya can make using some subset of coins with sum k.


  */
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;//it is possible to make sum of 0 using no coin
  for(int i = 1; i<n+1; i++){//for each coin from input array
      int val = coins[i-1];
      for(int j =  0; j<k+1; j++){ //we iterate through every possible sums from 0 to k, even if sum is lesser than k, 
      //it might be part of bigger sum equal to k, which'll get updated
          for(int y =  0; y<j+1; y++){//and for every such sum j, we check for each possible sum y from 0 to j that can 
          //be made using a subset of these selected coins
              dp[i][j][y] = dp[i-1][j][y];//for a sum of j using i-1 coins that has a subset sum of y, I can make this 
              //subset sum of y by using i coins as well by simply not including the new coin in the subset 
              if(j-val>=0){// if we can subtract current coin val from current sum j
                dp[i][j][y] |= dp[i-1][j-val][y];
                //if we can make a sum of j-current val using the first i-1 coins such that a subset of this subset has the sum y
                //then by simply including the current coin, we can make the sum of j using the first i coins such that subset of this subset has the sum y
                if(y-val>=0){ //if we can subtract current coin from subset that sums to y
                  dp[i][j][y] |= dp[i-1][j-val][y-val]; //that means on including it also it must be true
                }
              }
          }
          
      }
      
  }
  vector<int> ans;
  for(int i =  0; i<k+1; i++){//for all the possible sum values from 0 to k

      if(dp[n][k][i]){
        ans.push_back(i);//if it is possible to make that sum, we pushback i to the answers
      }
  }
  cout<<ans.size()<<endl;
  for(int x : ans){
    cout<<x<<" ";
  }
  cout<<endl;
  
  
  

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
