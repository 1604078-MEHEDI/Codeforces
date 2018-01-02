#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,b,p=-1,q=-1,x=1,m=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(p<a || q<b)
        {
            p = a;
            q = b;
            if(x>m)
            {
                m = x;
            }
            x = 1;
        }
        else
        {
            x++;
            if(i==n)
            {
                if(x>=m)
                {
                    cout<<x;
                    return 0;
                }
                else
                {
                    cout<<m;
                    return 0;
                }
            }
        }

    }
    cout<<m;
}
