#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long arr[100001],p=0;
    int n,i,m;
    cin>>n;

    for(i=0 ; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]>p)
        {
            p = arr[i];
            m = i;
        }
    }
    if(p==1)
        arr[m] = 2;
    else
    arr[m] = 1;
    sort(arr, arr+n);

    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
