#include<bits/stdc++.h>
using namespace std;


int main()
{
    int i,l,j,count=0,m=0,n=0;
    string s,str;
    cin>>s;
    l = s.length();
    for(i=1; i<l; i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            count++;
            if(count>=1)
            {
                cout<<s;
                return 0;
            }
        }
    }
    if(s[0]>='a' && s[0]<='z')
    {
        n++;
        s[0] = s[0] - 32;
        cout<<s[0];

        for(i=1; i<l; i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
               // m++;
                s[i] = s[i] + 32;
                cout<<s[i];
                if(i==l-1)
                {
                    //cout<<s[i];
                    return 0;
                }
            }
        }
    }
    for(i=0; i<l; i++)
    {
        if(n>=1)
            return 0;
        if(s[i]>='A' && s[i]<='Z')
        {
            s[i] = s[i] + 32;
            cout<<s[i];
            if(i==l-1)
            {
                //cout<<s[i];
                return 0;
            }

        }
    }

}

