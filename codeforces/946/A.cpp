#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,s1=0,s2=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a>=0)
            s1 +=a;
        else
            s2 +=a;
    }
    cout<<s1-s2;
    return 0;
}
