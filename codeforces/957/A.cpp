#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0,ar[101],j=0,p,a=0,q,t,m;
    cin>>n;
    string s;
    cin>>s;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='?')
        {
            count++;
            ar[j++] = i;
        }
        else if(s[i]==s[i+1])
        {
            cout<<"No";
            return 0;
        }
    }

    if(count>0)
    {
        //if(count==1)
       // {
            p = ar[0];

            if(p==0 || p==n-1)
            {
                cout<<"Yes";
                return 0;
            }
            if(count==1)
            {
            if(s[p-1]!=s[p+1])
            {
                cout<<"No";
                return 0;
            }
        }
     /*   t = ar[0];
        q = ar[j-1];
        if(t==0 || q==n-1)
        {
            cout<<"Yes";
            return 0;
        }*/

        for(int k=0; k<j; k++)
        {
            int m=0;
            p = ar[k];
            if(s[p-1]==s[p+1] || s[p]==s[p+1])
            {
                cout<<"Yes";
                return 0;
            }
        }
        if(m==0)
        {
            cout<<"No";
            return 0;
        }
    }
else
{
    cout<<"No";
}
}
