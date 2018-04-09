#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b,count=0,ar[10];
    long long x=9999999,y=9999999,z=9999999,w=9999999,s=9999999,p=9999999,t=9999999;
    cin>>n>>m>>a>>b;

    x = n*a;
    if(n%m==0)y = (n/m)*b;
    else w = ((n/m)+1)*b;
    if(m>=n)z = b;
    //cout<<z<<endl;

    while(n>0)
    {
        n --;
        count++;
        s = count*a;

        if(n%m==0)
        {
            p = (n/m)*b;

            t = s + p;
            break;
        }
    }
    ar[0] = x;
    ar[1] = y;
    ar[2] = z;
    ar[3] = w;
    ar[4] = t;

    sort(ar, ar+5);

    cout<<ar[0];
}
