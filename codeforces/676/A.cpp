#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ar[1001],n,i,p=0,q=1000,a,b,m,k,array[10];
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>ar[i];
        if(ar[i]>p)
        {
            p = ar[i];
            a = i;
        }
        if(q>ar[i])
        {
            q = ar[i];
            b = i;
        }
    }
   // cout<<a<<" "<<b<<endl;
   for(int j=0; j<10; j++)
   {
       array[j] = 0;
   }
    array[0] = abs(a-b);
    array[1] = abs(n-a);
    array[3] = abs(n-b);
    array[4] = abs(a-1);
    array[5] = abs(b-1);
    sort(array, array+6);
    cout<<array[5];
    return 0;
}
