#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,b,c,p,temp;
    cin>>a>>b>>c;
    if(a==b && a==c)
    {
        cout<<a;
        return 0;
    }
    if(a <= b && a<=c)
    {
        p = a+(b-a)/3+(c-a)/3;
        temp = (a+b+c) - p*3;
        if(temp > 3&&  (a > 0 && b > 0 && c > 0))cout<<p+1;
        else cout<<p<<endl;
        return 0;
    }
    if(b<=c && b<=a)
    {
        p = b+(a-b)/3+(c-b)/3;
        temp = (a+b+c) - p*3;
        if(temp > 3 &&  (a > 0 && b > 0 && c > 0))cout<<p+1;
        else cout<<p<<endl;
        return 0;
    }
    if(c<=b && c<=a)
    {
        p = c+(b-c)/3+(a-c)/3;
        temp = (a+b+c) - p*3;
        if(temp > 3 && (a > 0 && b > 0 && c > 0))cout<<p+1;
        else cout<<p<<endl;
        return 0;
    }
}
