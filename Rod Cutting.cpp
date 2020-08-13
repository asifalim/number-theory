#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j,mx;
        cin>>n;int ar[n],dp[n+1];dp[0]=0;
        for(i=0;i<n;i++)cin>>ar[i];dp[1]=ar[0];
        for(i=2;i<=n;i++)
        {
            mx=-1;
            for(j=1;j<i;j++)
            {
                 mx=max(mx,max(ar[i-1],dp[j]+dp[i-j]));

            }
            dp[i]=mx;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

