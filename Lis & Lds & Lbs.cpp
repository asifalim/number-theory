#include<bits/stdc++.h>
using namespace std;
int main()
{                   //Time complexity lis)O(nlogn) lds)O(nlogn) lbs)(nlogn+nlogn+n)
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j=1,mx=1,k,l=1;
        cin>>n;
        int ar[n],arr[n],len=1,c=1,lis[n],rlis[n],arrr[n],arrrr[n];lis[0]=rlis[0]=len;
        for(i=0,k=n-1;i<n;i++,k--)cin>>ar[i],arrr[k]=ar[i];arr[0]=ar[0];arrrr[0]=arrr[0];
        for(i=1;i<n;i++)             //finding lis
        {
           if(ar[i]<arr[0])arr[0]=ar[i],lis[j++]=1;
           else if(ar[i]>arr[len-1])len++,arr[c++]=ar[i],lis[j++]=len;
           else
           {
               int s=0,e=len-1,k,mid;
               while(s<=e)
               {
                   mid=(s+e)/2;
                   if(arr[mid]<ar[i])s=mid+1;
                   else k=mid,e=mid-1;
               }
               arr[k]=ar[i];lis[j++]=k+1;
           }
        }
        len=1;c=1;
        for(i=1;i<n;i++)             //finding lds
        {
           if(arrr[i]<arrrr[0])arrrr[0]=arrr[i],rlis[l++]=1;
           else if(arrr[i]>arrrr[len-1])len++,arrrr[c++]=arrr[i],rlis[l++]=len;
           else
           {
               int s=0,e=len-1,k,mid;
               while(s<=e)
               {
                   mid=(s+e)/2;
                   if(arrrr[mid]<arrr[i])s=mid+1;
                   else k=mid,e=mid-1;
               }
               arrrr[k]=arrr[i];rlis[l++]=k+1;
           }
        }
        for(i=0,j=n-1;i<n;i++,j--)mx=max(mx,rlis[j]+lis[i]-1);cout<<mx<<endl;  //lbs
        //for(i=0;i<n;i++)mx=max(mx,lis[i]);cout<<mx<<endl;   //lis
        //for(i=0;i<n;i++)mx=max(mx,rlis[i]);cout<<mx<<endl;    //lds
    }
    return 0;
}
