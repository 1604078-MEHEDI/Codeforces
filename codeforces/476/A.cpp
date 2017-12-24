#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,p;
    cin>>n>>m;
    if(m>n)
    {
        cout<<"-1";
        return 0;
    }
    if(n%2==0)
    {
        ///  for(i=1; i<=n; i++)
        //{
        p = (n/2);
        if(p%m==0)
        {
            cout<<p;
            return 0;
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                p++;
                if(p%m==0)
                {
                    cout<<p;
                    return 0;
                }
            }
        }
    }
    //}
    else
    {
        ///   for(i=1; i<=n; i++)
        //{
        p = (n/2)+1;
        if(p%m==0)
        {
            cout<<p;
            return 0;
        }
        else
        {
            for(i=1; i<=n; i++)
            {
                p++;
                if(p%m==0)
                {
                    cout<<p;
                    return 0;
                }
            }
        }
    }
    // }
    cout<<"-1";
    return 0;
}
