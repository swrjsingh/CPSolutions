#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long int
using namespace std;
const int S = 1e6 + 100;
const int s=200005;

int block,n,m;
int l,r,x;
int a[s],mp[S];
ll ans[s],sum;

struct query
{
    int l,r,idx;
}q[s];

bool cmp(query a,query b)
{
    if(a.l/block!=b.l/block)
        return a.l<b.l;

    return a.r<b.r;
}

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    block=450;

    for(i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    for(i=0; i<m; i++)
    {
        scanf("%d%d",&l,&r);
        q[i].l=l-1;q[i].r=r;q[i].idx= i;
    }

    sort(q,q+m,cmp);

    int cl,cr;
    int pl,pr;
    pl=0;pr=0;sum=0;
    for(i=0; i<m; i++)
    {
        cl=q[i].l;
        cr=q[i].r;

        while(pl>cl)
        {
            pl--;
            x=a[pl];

            sum-=(ll)mp[x]*mp[x]*x;
            mp[x]++;
            sum+=(ll)mp[x]*mp[x]*x;
        }

        while(pl<cl)
        {
            x=a[pl];

            sum-=(ll)mp[x]*mp[x]*x;
            mp[x]--;
            sum+=(ll)mp[x]*mp[x]*x;

            pl++;
        }

        while(pr<cr)
        {
            x=a[pr];

            sum-=(ll)mp[x]*mp[x]*x;
            mp[x]++;

            sum+=(ll)mp[x]*mp[x]*x;

            pr++;
        }

        while(pr>cr)
        {
            pr--;
            x=a[pr];

            sum-=(ll)mp[x]*mp[x]*x;
            mp[x]--;

            sum+=(ll)mp[x]*mp[x]*x;
        }

        ans[q[i].idx]=sum;
    }

    for(i=0; i<m; i++)
        printf("%I64d\n",ans[i]);

    return 0;
}