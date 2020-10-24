#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mulmod(ll base,ll n,ll mod)
{
    ll res=0;
    base=base%mod;
    while(n)
    {
        if(n&1)res=(res+base)%mod;
        base=(base*2LL)%mod;
        n>>=1;
    }
    return res%mod;
}
ll binpower(ll base,ll n,ll mod)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=mulmod(res,base,mod);
        base=mulmod(base,base,mod);
        n>>=1;
    }
    return res%mod;
}
bool isprime(ll n,ll k=5)
{
    if(n<=4)return n==2 or n==3;
    while(k)
    {
        ll a=2+rand()%(n-3);
        if(__gcd(n,a)!=1)return false;
        if(binpower(a,n-1,n)!=1)return false;
        k--;
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n;
        cout<<(isprime(n)?"Yes":"No")<<endl;
    }
    return 0;
}
