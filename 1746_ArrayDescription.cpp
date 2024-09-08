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
//=======================

const int N = 1e5+1, M = N;
vi g[N];
int a[N];
int dp[N];
//let dp[i] store
//let our function return how many more we add
//to possibilities on reaching ith index

int rec(int i, int chosen, int m, const int n){
    if(i==n) return 0; //We've crossed our final element

    if(a[i]!=0){ // If next element is not up to us
            if(abs(chosen-a[i])>1) return 0; // If it doesn't go with the next element
            else return 1;//If it goes with the next element
    }
    //if we have reached the last element
    //if(dp[i]!=-1) return dp[i]; 

    if(a[i]==0){ // Element is up to us
        vector<int> possible; // It can take 3 possible values values
        
        for(int j = -1; j<=1; j++){
            if(chosen+j>=1 && chosen+j <=m) possible.push_back(chosen+j); // which must lie b/w with 1 to m
        }
        int ans=0;
        for(int choose : possible){
            ans = ans + rec(i+1, choose, m,n); //we now check from here how many elements are left
        }
        return ans;
    }

    /*
    If last element, and is not 0
    If last elemtn, and is 0
    If not last element, and is not 0

    */
}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i =  0; i<n; i++){
        cin>>a[i];
        //dp[i]=-1;
    }
    for(int i = 0; i<n; i++){
        //if(dp[i]!=-1)
    }
    if(n==1){
        cout<<((a[0]) ? 1 : m);
        return;
    }
    else{
        if(a[0]==0){
            int ans = 0;
            for(int i = 1; i<=m; i++){
                ans+=rec(1,i,m,n);
            }
            cout<<ans;
        }
        else{
            cout<<rec(1,a[0],m,n);
        }
    }

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

