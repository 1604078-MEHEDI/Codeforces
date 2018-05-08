#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int n, ar[1000];

int main()
{
    cin >> n;
    int l = 0, x = n, cnt = 0;

    while(x > 0)
    {
        ar[++l] = x % 10;
        x /= 10;
        cnt = max(cnt, ar[l]);
    }

    cout<<cnt<<endl;

    for(int i = 1; i <= cnt; i++)
    {
        long long v = 0;
        for(int j = l; j > 0; j--)
        {
            v = v * 10;
           // cout<<j<<" ";
            if(ar[j] >= i) v++;
        }
        cout<< v <<" ";
    }
    cout<<endl;
    return 0;
}
