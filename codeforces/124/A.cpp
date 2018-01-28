#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,p;
    cin>>n>>a>>b;
    cout<<n-max(a+1,n-b)+1;
    return 0;
}
