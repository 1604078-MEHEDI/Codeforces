#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n,i=1, count=0;
    cin>>n;

    while(n >= 0)
    {
        if(n <= 0)break;
        count++;
        if(i % 2 == 0)n--;
        else n -= 2;
        i++;
    }
    cout<<count;
    return 0;
}
