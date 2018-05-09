#include<bits/stdc++.h>
using namespace std;

int ar[10001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,i;
    int sareja = 0,dima = 0;

    cin >> n;
    for( int j = 0; j < n; j++)
    {
        cin >> ar[j];
    }
    int cnt =0;
    i = 0;
    int k = n - 1;
    int ss = 0,dd = 0,mx;
    while(i <= k)
    {
        cnt++;
        if(ar[i] > ar[k]) mx = ar[i++];
        else   mx = ar[k--];
        if(cnt % 2 == 1)
        {
            sareja += mx;
        }
        else
            dima += mx;
    }
    cout<<sareja <<" "<<dima<<endl;
    return 0;
}
