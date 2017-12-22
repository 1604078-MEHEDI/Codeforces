#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,p=0,q=0,count=0;
    cin>>n;
    for(i=1;i<=n; i++)
    {
        cin>>a;
        if(p<=a)
        {
            p = a;
            count++;
            if(count>q)
            {
                q = count;
            }
        }
        else
        {
            p = a;
            count=1;
        }
    }
        cout<<q;
}
