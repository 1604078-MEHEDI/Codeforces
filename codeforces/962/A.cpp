#include<bits/stdc++.h>
using namespace std;

double ar[9999999];

int main()
{
    ios_base::sync_with_stdio(0);

    double n,a,sum=0,test=0,p=0,result=0;
    long long i;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>ar[i];
        sum +=ar[i];
    }
    test = sum/2;
    for(i=1; i<=n; i++)
    {
        result +=ar[i];
        if(result >= test )
        {
            cout<<i<<endl;
            break;
        }
    }
}
