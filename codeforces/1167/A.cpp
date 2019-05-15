#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '8')
            {
                pos = i+1;
                break;
            }
        }
        if(n - pos >= 10 && pos > 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
