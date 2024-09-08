#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define umpii unordered_map<int,int>
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
{int ans=1;while(b>0){if(b&1)ans=((ans%m)*(a%m))%m;
a=((a%m)*(a%m))%m;b>>=1;}return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};
 
const int N = 1e5+1;
 
stack<int> s;
vi a,b;
vec(bool) vis;
 
void dfs(int i)
{
	vis[i]=true;
	if(b[i]>=0 and !vis[b[i]])
		dfs(b[i]);
	s.push(i);
}
 
void solve()
{
	int i,j,n,ans=0;
	cin>>n;
	a.resize(n);
	b.resize(n);
	vis=vec(bool) (n,false);
	vi v1,v2;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		b[i]--;
	}
	for(i=0;i<n;i++)
	{
		if(!vis[i])
		dfs(i);
	}
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		ans+=a[i];
		if(a[i]>0 and b[i]!=-1)
		{
			a[b[i]]+=a[i];
			v1.pb(i+1);
		}
		else
		v2.pb(i+1);
	}
	cout<<ans<<endl;
	for(i=0;i<v1.size();i++)
	cout<<v1[i]<<" ";
	if(v2.size())
	{
		for(i=v2.size()-1;i>=0;i--)
		cout<<v2[i]<<" ";
	}
	cout<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--)
		solve();
}