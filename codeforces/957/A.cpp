#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    string s;
    cin>>s;

    for(i=0; i<n-1; i++)
    {
        if(s[i] != '?' && s[i]==s[i+1])
        {
            cout<<"No";
            return 0;
        }
    }

    for(i=0; i<n; i++)
    {
        if(s[i] == '?')
        {
            if(i == 0 || i==n-1)
            {
                cout<<"Yes";
                return 0;
            }
            if(s[i+1] == '?')
            {
                cout<<"Yes";
                return 0;
            }
            if(s[i-1] == s[i+1])
            {
                cout<<"Yes";
                 return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
