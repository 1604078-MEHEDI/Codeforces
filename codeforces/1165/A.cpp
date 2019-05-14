#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int d = y;
    int cnt = 0, i;
    for( i = n - 1; i > 0; i--)
    {
        if(d <= 0)
        {
            if(s[i] == '0')cnt++;
            break;
        }
        if(s[i] == '0')
        {
            d--;
        }
        else
        {
            d--;
            cnt++;
        }
    }
    d = x - y - 1;
    for(int k = i-1; k > 0; k--)
    {
        if(d <= 0)
        {
            break;
        }
        if(s[k] == '0')
        {
            d--;
        }
        else
        {
            d--;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
