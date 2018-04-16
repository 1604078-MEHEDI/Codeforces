#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n,m,z;
    int i,count=0;

    cin>>n>>m>>z;

    for(i=0; i<=z; i +=n)
    {
        if(i % m == 0)count++;
    }

    cout<<count-1;
    return 0;

}
