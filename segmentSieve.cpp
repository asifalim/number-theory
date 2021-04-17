#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cout<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e9
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
#define case(k) cout<<"Case "<<++kk<<": ";
int t,kk=0,ans=0,tot=0,k;
const int mxN=5e4+4,mod=1e9+7;     //mxN = sqrt(range)
int vis[mxN+2];
vector<int>prime;
void sieve()
{
    vis[1]=1;
    for(int i=2; i*i<mxN; i++)if(!vis[i])for(int j=i*i; j<mxN; j+=i)vis[j]=1;
    for(int i=2; i<mxN; i++)if(!vis[i])prime.push_back(i);
}
void segment(ll l, ll r)
{
    bool segprime[r-l+1];
    mem(segprime,true);
    if (l == 1) segprime[0] = false;
    for (int i = 0; prime[i]*prime[i] <= r; ++i)
    {
        int currentPrime = prime[i];
        ll base = (l/currentPrime)*currentPrime;
        if (base < l) base += currentPrime;
        for (ll j = base; j <= r; j += currentPrime)segprime[j-l] = false;
        if (base == currentPrime) segprime[base-l] = true;
    }
    for (int i = 0; i < r - l + 1; ++i)if (segprime[i]) cout << (i+l) << endl;
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        segment(l, r);
    }
    return 0;
}
