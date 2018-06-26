#include<bits/stdc++.h>
using namespace std;
int ar[123456];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for(int i =0; i < n; i++)
    {
        cin >> ar[i];
    }
    int mx = 0;
    for(int i =0; i < n; i++)
    {
        int cnt = 0;
        int p = ar[i];
        int q = ar[i];
        for(int k = i; k >= 0; k--)
        {
            if(ar[k] <= p)
            {
                cnt++;
                p = ar[k];
                mx = max(mx, cnt);
            }
            else break;

        }
        for(int j = i + 1; j < n; j++)
        {
            if(ar[j] <= q)
            {
                cnt++;
                q = ar[j];
                mx = max(mx, cnt);
            }
            else break;
        }
    }
    cout<<mx<<endl;
    return 0;
}
