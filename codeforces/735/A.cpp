#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,p,q;
    cin>>n>>k;
    string str;

    cin>>str;

    for(i=0; i<n; i++)
    {
        if(str[i]=='G')
            p = i;
        if(str[i]=='T')
            q = i;
    }

    if(p>q)
    {
        i = q;
        while(n>i)
        {
            i = i+k;
            if(str[i]=='#')
            {
                cout<<"NO";
                return 0;
            }

            else if(str[i]=='G')
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    else
    {
        i = p;
        while(n>i)
        {
            i = i+k;
            if(str[i]=='#')
            {
                cout<<"NO";
                return 0;
            }

            else if(str[i]=='T')
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}
