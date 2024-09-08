#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
 
const int N = 2*1e5+5;
int n,k;
 
bool check(int m,vector<int> a,int flag)
{
	int cnt=0;
	for(auto x:a)
	{
		if(x<=m or cnt%2==!flag)
		cnt++;
	}
	return cnt>=k;
}
 
int main()
{
    cin>>n>>k;
	vector<int> a(n);
	for(auto &x:a)
	cin>>x;
	int l=1,h=1e9+7,m;
	while(l<h)
	{
		m=(l+h)/2;
		if(check(m,a,0) or check(m,a,1))
			h=m;
		else
			l=m+1;
	}
	cout<<l<<endl;
}