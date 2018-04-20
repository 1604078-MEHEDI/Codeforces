#include<bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if(x% y == 0)return y;
    return gcd(y, x%y);
}
int lcm(int x, int y)
{
    return (x*y)/gcd(x,y);
    //return l;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x,y,a,b,i=0,l,m,count=0,w;
    cin>>x>>y>>a>>b;

     m = lcm(x,y);
     //cout<<m<<endl;
 /*   while(1)
    {
        i++;
        w = i*m;
        if(w >= a && w <= b)count++;
        else if(w > b)break;
    }*/
    cout<<(b/m) - ((a-1)/m)<<endl;

   // cout<<count<<endl;
    return 0;
}
