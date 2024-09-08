#include <bits/stdc++.h>
using namespace std;
int n,x,L,R=1000;
int main(){
cin>>n>>x;
for(int a,b;cin>>a>>b;){
if(a>b)swap(a,b);
L=max(L,a),R=min(R,b);
}
cout<<(L>R?-1:L<=x&&R>=x?0:L>x?L-x:x-R);
}