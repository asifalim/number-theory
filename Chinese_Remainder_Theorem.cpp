#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int num[14],rem[14];
void extended_euqlid(ll a,ll b,ll &x,ll &y)
{
    if(!b)x=1,y=0;
    else extended_euqlid(b,a%b,y,x),y-=(a/b)*x;
}
ll chinese_remainder(ll n)
{
    ll mul=1,res=0,x,y;
    for(int i=0;i<n;i++)mul*=num[i];
    for(int i=0;i<n;i++)
    {
        ll pp=mul/num[i];
        extended_euqlid(pp,num[i],x,y);
        res=(res+rem[i]*x*pp)%mul;
    }
    return (res+mul)%mul;
}
int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        for(i=0;i<n;i++)cin>>num[i]>>rem[i];
        cout<<"Case "<<k++<<": "<<chinese_remainder(n)<<endl;
    }
}
