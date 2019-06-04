#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[2*n+2];
    long long sum1 = 0, sum2 = 0;
    for(int i = 1; i <= 2*n; i++)
    {
        cin >> a[i];
        if(i <= n)sum1 += a[i];
        else sum2 += a[i];
    }
    if(sum1 != sum2)
    {
        for(int i = 1; i <= 2*n; i++) cout << a[i] << " ";
        return 0;
    }
    sort(a+1, a+ 2*n+1);

    sum1 = 0;
    sum2 = 0;
    for(int i = 1; i <= 2*n; i++)
    {
        if(i <= n)sum1 += a[i];
        else sum2 += a[i];
    }

    if(sum1 != sum2)
    {
        for(int i = 1; i <= 2*n; i++) cout << a[i] << " ";
        return 0;
    }
    cout << "-1\n";
    return 0;
}
