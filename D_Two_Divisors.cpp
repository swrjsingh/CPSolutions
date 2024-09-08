/*#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long int
using namespace std;
const int N = 1e5 + 10;
vector<bool> prime;
vector<int> factor;

void sieve(int n){
    prime.assign(n+1,true);
    factor.assign(n+1,0);
    prime[0]=prime[1]=false;
    for(ll i = 2; i<=n; i++){
        if(prime[i]){
            factor[i]=i;
            for(ll j = i*i; j<=n; j+=1){
                if(prime[j]){
                    prime[j] = false;
                    factor[j] = i;
                }
            }
        }
    }
}
void solve(){
    ll n,a;
    cin>>n;
    vector<pair<int,int>> divs;
    for(int i =  0; i<n; i++){
        cin>>a;
        int p = factor[a];
        ll x = a, d1 = 1, d2 = a;
        while(x%p==0){
            x=x/p;
            d1*=p;
        }
        d2=a/d1;
        if(d1>1&&d2>1){
            divs.push_back({d1,d2});
        }
        else{
            divs.push_back({-1,-1});
        }
    }
    for(int i =  0; i<n; i++){
        cout<<divs[1].first<<' ';
    }
    cout<<'\n';
    for(int i =  0; i<n; i++){
        cout<<divs[i].second<<" ";
    }
    
    
    
}
int main(){
    sieve(1e7+5);
    solve();
}*/
#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
const double pi = acos(-1);
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};
 
const int N = 1e5+1;
 
vec(bool) isPrime;
vi sFactor,primes;
 
void sieve(int n)
{
	isPrime.assign(n+1,true);
	sFactor.assign(n+1,0);
	isPrime[0]=isPrime[1]=false;
	primes={};
	for(int i=2;i<=n;i++)
	{
		if(isPrime[i])
		{
			sFactor[i]=i;
			primes.pb(i);
			for(int j=i*i;j<=n;j+=i)
			if(isPrime[j])
			{
				isPrime[j]=false;
				sFactor[j]=i;
			}
		}
	}
}
 
void solve()
{
	int i,j,n,a;
	cin>>n;
	vii ans;
	for(i=0;i<n;i++)
	{
		cin>>a;
		int p=sFactor[a];
		int x=a,d1=1,d2;
		while(x%p==0)
		{
			x=x/p;
			d1=d1*p;
		}
		d2=a/d1;
		if(d1>1 and d2>1 and __gcd(d1,d2)==1)
		ans.pb({d1,d2});
		else
		ans.pb({-1,-1});
	}
	for(auto x:ans)
	cout<<x.ff<<" ";
	cout<<endl;
	for(auto x:ans)
	cout<<x.ss<<" ";
	cout<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	sieve(1e7+5);
	while(t--)
		solve();
}