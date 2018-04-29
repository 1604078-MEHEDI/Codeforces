#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 4000007
int ar[MAX];

int main()
{
    IO
    int n,a,b,p,sum =0,count=0;
    cin>>n>>a>>b;
    for(int i = 0; i< n; i++)
    {
        cin>>ar[i];
        sum += ar[i];
    }
     p = ar[0];
     sort(ar+1, ar+n);
     //for(int i =0 ; i< n; i++)
        //cout<<ar[i]<<" ";
     //cout<<endl;
     int j = 0;
for(int i = 0; i < n ; i++)
{
    double result = (a*p)/sum;

    if(result >= b && sum >= p)
    {
        cout<<count<<endl;
        return 0;
    }

    else
    {
        j++;
        sum -= ar[n-j];
        count++;
    }
}

cout<<(n-1)<<endl;
return 0;
}
