#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long
int ar[1234567];

int main()
{
    IO
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar+n);
    cout<<ar[(n-1)/2]<<endl;
    return 0;
}
