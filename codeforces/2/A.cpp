#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main()
{
    IO
    long long n,mx = 0;
    map <string, long long> score, ss;
    cin >> n;
    string s[n];
    int x[n];

    for(int i = 0; i < n; i++)
    {
        cin >> s[i] >> x[i];
        score[s[i]] += x[i];
    }

    for( map <string, long long>::iterator it = score.begin(); it != score.end(); it++)
    {
        mx = max(it->second, mx);
    }

    for(int i = 0; i < n; i++)
    {
        ss[s[i]] += x[i];

        if(ss[s[i]] >= mx && score[s[i]] == mx)
        {
            cout<< s[i];
            break;
        }
    }

    return 0;
}
