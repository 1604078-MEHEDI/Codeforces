#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main()
{
    double a1,a2,a3,b1,b2,b3,n,i,t,x,y;
    cin>>a1>>a2>>a3>>b1>>b2>>b3>>n;
    x = a1+a2+a3;
    y =b1+b2+b3;
   // cout<<x<<" "<<y;
    t = ceil(x/5) + ceil(y/10);
    //cout<<" "<<t<<" ";
    if(n>=t)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
