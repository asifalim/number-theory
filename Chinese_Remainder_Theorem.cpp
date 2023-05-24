#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF (1LL<<61)
int t,cs=0;
const int mxn=1e6+2,mod=1e9+7;
int inverse(int64_t a,int64_t b)
{
    int64_t x=1,y=0,md=b,prev;
    while(b)
    {
        prev=y;
        y=x-(a/b)*y,x=prev;
        a=a%b;
        swap(a,b);
    }
    if(x<0)x+=md;
    return x;
}
int32_t main()
{

    //fast;
    w(t)
    {
        int n;
        cin>>n;
        array<int,2>ar[n];
        int64_t MUL=1;
        for(int i=0; i<n; i++)cin>>ar[i][0]>>ar[i][1],MUL=1LL*MUL*ar[i][0];
        int64_t ans=0;
        for(int i=0; i<n; i++)
        {
            int rem=ar[i][1];
            int64_t mul=MUL/ar[i][0];
            int inv=inverse(mul,ar[i][0]);
            ans+=1LL*rem*mul*inv,ans%=MUL;
        }
        cout<<"Case "<<++cs<<": "<<ans<<endl;
    }
}
