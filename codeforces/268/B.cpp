#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,sum=0;
    cin>>n;
    for(i=1; i<n; i++)
    {
        sum +=(n-i)*i;
    }
    cout<<sum+n;
}
