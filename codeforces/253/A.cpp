#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string str;
    int b,g;
    cin>>b>>g;
    if(b==g)
    {
        for(int i=1; i<=b; i++)
        {
            str +="BG";
        }
        cout<<str;
    }
    else if(b>g)
    {
        for(int i=1; i<=g; i++)
        {
            str +="BG";
        }
        for(int i=1; i<=b-g; i++)
        {
            str +="B";
        }
        cout<<str;
    }
    else
    {
        for(int i=1; i<=b; i++)
        {
            str +="GB";
        }
        for(int i=1; i<=g-b; i++)
        {
            str +="G";
        }
        cout<<str;
    }
}
