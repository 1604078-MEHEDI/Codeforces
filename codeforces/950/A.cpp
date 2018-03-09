#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,l,r;
    cin>>l>>r>>a;

    while(1)
    {
        if(a==0)
        {
            if(l>=r)
            {
                cout<<2*r;
                return 0;
            }
            else
            {
                cout<<2*l;
                return 0;
            }
        }
        if(l==r)
        {
            int p;
            p = (l+r+a)/2;
            cout<<2*p;
            return 0;
        }
        if(l>r)
        {
            r++;
            a--;
        }
        else if(l<r)
        {
            l++;
            a--;
        }
    }
}
