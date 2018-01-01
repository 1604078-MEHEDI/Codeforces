#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,x=0,y=0;
    string s;
    cin>>n>>s;
    for(i=0; i<n; i++)
    {
        //cin>>s[i];
        if(s[i]=='1')
        {
            x++;
        }
        if(s[i]=='0')
        {
            y++;
        }
        if(x==n){cout<<x;
        return 0;}
        if(y==n){cout<<y;
        return 0;}
    }
    if(x>=y)
    {
        cout<<x-y;
    }
    else
    {
        cout<<y-x;
    }
}
