#include<bits/stdc++.h>
using namespace std;

int main()
{
    double t,s,f,x;
    int h,m,q,p,r,H,D,C,N,z,y;
    cin>>h>>m;
    cin>>H>>D>>C>>N;

    if(h>=20)
    {
        if(H%N==0)
            q = (H/N);
        else q = H/N+1;
        t = (q*C)*0.8;
        printf("%.4lf",t);
    }
    else
    {
        if(H%N==0)
            p = (H/N);
        else p = (H)/N+1;
        x = p*C;
        y = (20-h)*60 - m;
        z = (y*D)+H;

        if(z%N==0)
        {
            r = (z/N);
            f = (r*C)*0.8;
        }
        else
        {
            r = (z/N)+1;
            f = (r*C)*0.8;
        }
        s = min(x,f);
        printf("%.4lf",s);
    }

}
