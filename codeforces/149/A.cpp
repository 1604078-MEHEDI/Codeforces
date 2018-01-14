#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ar[101],sum=0,i,count=0,k=0;
    cin>>n;
    for(i=0; i<12; i++)
    {
        cin>>ar[i];
    }
    sort(ar, ar+12);
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    for(int j=11; j>=0; j--)
    {
        //cout<<ar[j]<<" ";
        count++;
        sum +=ar[j];
        if(sum>=n)
        {
            k++;
            cout<<count;
            //cout<<" "<<i;
            return 0;
        }
    }
    if(k==0)
    {
        cout<<"-1";
        return 0;
    }
}
