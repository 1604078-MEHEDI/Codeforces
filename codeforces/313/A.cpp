#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,p,q,m,x,y;
    cin>>n;
    if(n>0)
    {
        cout<<n;
        return 0;
    }
    else
    {
        p = abs(n%10);
        x = n%10;
     //   cout<<p<<" "<<x<<endl;
        n /=10;
        q = abs(n%10);
        y = n%10;
        m = n/10;
     //   cout<<q<<" "<<m<<endl;
        if(p>=q)
        {
            cout<<n;
            return 0;
        }
        else
        {
            if(m==0)
                cout<<x;
            else
                cout<<m<<p;
        }
    }
}
