#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,count=0,i;
    cin>>k;

    while(k>=0)
    {
        if(k%2==0)
        {
            n = k/2;
            break;
        }
        else
        {
            k -= 3;
            count++;
        }
    }

    cout<<n+count<<endl;

    for(i=0; i<n; i++)
        cout<<2<<" ";
    for(int j=0; j<count; j++)
        cout<<3<<" ";
}
