#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n,a,b,c,i,count=0,x,y;
    cin>>n>>a>>b;
    while(1)
    {
        x = a%10;
        y = b%10;
        if(x==7 || y==7)
        {
            cout<<count<<endl;
            // cout<<a<<" "<<b<<endl;
            return 0;
        }
        b -=n;
        count++;
        if(a==0)
        {
            a=23;
            b=60+b;
        }
        if(b<0)
        {
            a --;
            b = 60+b;
          //  cout<<b<<" ";
        }
    }
}
