#include<bits/stdc++.h>
using namespace std;
int a[1234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mx = 0;
    for(int i =0; i < n; ++i)
    {
        int j = i;
        //long long p = a[i] * 2;
        while(j+1 < n && a[j+1] <= a[j]*2)
        {
            ++j;
        }
            mx = max(mx, j - i + 1);
            i = j;
        //cout<<low<<" "<<hi<<" "<<p<<" "<<(hi-i)<<endl;
    }
    cout<<mx<<endl;
}
