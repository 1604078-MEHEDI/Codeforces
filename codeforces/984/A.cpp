#include<bits/stdc++.h>
using namespace std;
int ar[10001];
//deque<int>dq;

int main()
{
    long long n;
    cin >> n;
    for(int i = 0; i <n; i++)
    {
        cin >> ar[i];
    }
    sort(ar, ar+n);

    if(n % 2 == 0)
        cout<<ar[n/2 - 1]<<"\n";
    else
        cout<<ar[n/2]<<"\n";
    return 0;


}
