#include<bits/stdc++.h>
using namespace std;
int ar[200],temp[200][200];
int same[30][30];
void print(int i,int j,char& c)
{
    if(i==j)
    {
        cout<<c++;
        return;
    }
    cout<<"(";
    print(i,same[i][j],c);
    print(same[i][j]+1,j,c);
    cout<<")";
}
int main()
{                         //Time complexity O(n^3)
    int t;
    cin>>t;
    while(t--)
    {
        int r,i,j,q=0,k,l;
        char ch='A';
        cin>>r;
        for(i=0;i<r;i++)cin>>ar[i];
        for(l=2; l<r; l++)
        {
            for(i=0; i<r-l; i++)
            {
                j=i+l;
                temp[i][j]=INT_MAX;
                for(k=i+1; k<j; k++)
                {
                    q=temp[i][k]+temp[k][j]+ar[i]*ar[j]*ar[k];
                    if(q<temp[i][j])temp[i][j]=q,same[i+1][j]=k;
                }
            }
        }
        cout<<temp[0][r-1]<<endl;  //minimum multiply needed
        print(1,r-1,ch);cout<<endl;  //valid parentheses for minimum multiply
    }
    return 0;
}
