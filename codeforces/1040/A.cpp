#include<bits/stdc++.h>
using namespace std;
int a[101];

int main()
{
    int n,w,b;
    cin >> n >> w >> b;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int j = n;
    int ans = 0;
    for(int i = 1; i <= (n+2-1)/2; i++)
    {
        if(a[i] == a[j] && j > i)
        {
            if(a[i] == 2)
            {
                int mn = min(w,b);
                ans += mn*2;
                j--;
            }
            else
            {
                j--;
                continue;
            }
        }
        else if(a[i] == 0 && j > i)
        {
            if(a[j] == 2)
            {
                ans += w;
                j--;
            }
            else
            {
                cout<<"-1\n";
                return 0;
            }
        }
        else if(a[i] == 1 && j > i)
        {
            if(a[j] == 2)
            {
                ans += b;
                j--;
            }
            else
            {
                cout<<"-1\n";
                return 0;
            }
        }
        else if(a[i] == 2)
        {
            if(a[j] == 0 && j > i){
                    ans+=w;
            }
            else if(a[j] == 1 && j > i)ans += b;
            else ans += min(w,b);
            j--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
