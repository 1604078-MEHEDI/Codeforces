#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

LL fact(LL n)
{
    if(n > 1)
        return n* fact(n - 1);
    else
        return 1;
}

int main()
{
    IO
    LL a,b,result=1,c,i;

    cin >> a >> b;
    c = b - a;
    if(c >= 5)
    {
        cout<<"0"<<"\n";
    }
    else
    {
        for(i = a+1; i <= b; i++)
            result =(result*(i%10))%10;
        cout<<result<<"\n";
    }
    return 0;
}
