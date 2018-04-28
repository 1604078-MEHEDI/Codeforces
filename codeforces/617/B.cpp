#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,ar[1000],product  = 1,j=0,cnt=0;
   // ar[0] = 0;
    cin>>n;

    for(int i = 1; i<=n; i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            cnt++;
            ar[j++] = i;
        }
    }

    for(int k = 0; k < j-1; k++)
    {
        product *= ar[k+1] - ar[k];
    }
    if(cnt == 0)
    {
        cout<<"0"<<endl;
        return 0;
    }
    cout<<product<<endl;
    return 0;
}
