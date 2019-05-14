#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    queue<char>Q;
    for(int i = 0; i < n; i++)Q.push(s[i]);
    string ans = "";
    while(!Q.empty())
    {
        char ch = Q.front();
        Q.pop();
        cnt++;
        while(!Q.empty())
        {
            char x = Q.front();
            Q.pop();
            if(ch != x)
            {
                ans += ch;
                ans += x;
                cnt--;
                break;
            }
            else cnt++;
        }
    }
    cout << cnt << "\n";
    cout << ans << "\n";
    return 0;
}

