#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m=0;
    cin>>n;
    while(n>0)
    {
        if(n%2==1)
            m++;
        n /=2;
    }
    cout<<m;
}
