#include<bits/stdc++.h>
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define ll long long
using namespace std;
const int N = 1e5 + 10;

int arr[200005];

int main()
{
    int n,ans=0,maxi,range;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    maxi=arr[n-1];
    for(int i=0;i<n;i++)
    {
        if(i && (arr[i]==arr[i-1])){//if non first element(ie zeroeth element) and if last(ie if second last is same as last then just go to next element)
            continue;//then just go to next iteration
        }
        int tmp=arr[i]*2;//double of ith element
        range=arr[n-1]/arr[i];
        range=(range+1)*arr[i];
        while(tmp<=range)
        {
            int p=lower_bound(arr,arr+n,tmp)-arr;
            if(p>0)
            ans=max(ans,arr[p-1]%arr[i]);
            tmp+=arr[i];
        }
    }
    printf("%d",ans);
    return 0;
}