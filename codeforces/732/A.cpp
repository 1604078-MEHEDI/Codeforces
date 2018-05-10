#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,i,m,p;
    cin>>n>>m;
    for(i=1; i <= 10; i++)
    {
        p = (n*i)%10;
        if(p==0 || p == m)
        {
            cout<<i;
            return 0;
        }
    }
}
