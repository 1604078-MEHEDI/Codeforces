#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n,m,a,b,i,x=0,p,y;
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        p = b/a;
        if(p>x)
        {
            x = p;
        y = (a*m)/b;
        }
    }
    printf("%.8lf",y);
    return 0;
}
