#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0,arr[100001],j=0,a=0;
    string s;
    cin>>n;
    cin>>s;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='1')
        {
            count++;
            if(i!=n-1)
                continue;
        }
        a++;
        arr[j++] = count;
        count = 0;
    }
    if((s[n-1])=='0')
    {
        for(int i=0; i<j; i++)
        {
            cout<<arr[i];
        }
        cout<<'0';
    }
    else
    for(int i=0; i<j; i++)
        {
            cout<<arr[i];
        }

}
