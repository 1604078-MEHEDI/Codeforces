#include<bits/stdc++.h>
using namespace std;

int ar[10001];


int main()
{
    int n,sum = 0,i;
    int sareja = 0,dima = 0;

    cin >> n;

    for( int j = 0; j < n; j++)
    {
        cin >> ar[j];
        sum += ar[j];
    }
    int cnt =0;
    i = 0;
    int k = n - 1;
    int ss = 0,dd = 0;
    while(1)
    {
        int mx = max(ar[i], ar[k]);

        if(ss == 0)
        {
            if(mx == ar[i])i++;
            if(mx == ar[k])k--;
            sareja += mx;
            ss++;
            dd = 0;
        }
        else if(dd == 0)
        {
            if(mx == ar[i])i++;
            if(mx == ar[k])k--;
            dima += mx;
            ss = 0;
            dd++;
        }
        cnt++;
        if( cnt >= n)break;
    }
    cout<<sareja <<" "<<dima<<endl;
    return 0;
}
