#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ab=12,ba=21,j=0,t1=0,t2=0,k1=0,k2=0,l=0;
    string str,s;
    cin>>str;

    for(int i=0; i<=str.length(); i++)
    {
        if(str[i]=='A' && str[i+1]=='B' && t1==0)
        {
            ab = i+ 1;
            l = i;
            t1 = 1;

        }
        if(str[i]=='B' && str[i+1]=='A')
        {
            ba = i;
            j = i+1;
            t2 = 1;
        }
    }

    if(ab != ba && t1==1 && t2==1 && j != l )
    {
        cout<<"YES"<<endl;
        return 0;
    }
    for(int i=0; i<=str.length(); i++)
    {
        if(str[i]=='A' && str[i+1]=='B')
        {
            ab = i+ 1;
            l = i;
            k1 = 1;

        }
        if(str[i]=='B' && str[i+1]=='A' && k2==0)
        {
            ba = i;
            j = i+1;
            k2 = 1;
        }
    }
    if(ab != ba && k1==1 && k2==1 && j != l )
    {
        cout<<"YES"<<endl;
        return 0;
    }
    else
        cout<<"NO"<<endl;
}
