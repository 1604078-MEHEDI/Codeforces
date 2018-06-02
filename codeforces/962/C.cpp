#include <bits/stdc++.h>
#define LL long long
#define PLL pair<LL, LL>
#define mp make_pair
#define ff first
#define ss second
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


int main()
{
    IO
    string s;
    cin >> s;
    long long ans = 1e15;
    for(int i= 1; i < 50000; i++)
    {
        long long num = i*i;
        string str;
        stringstream sub;
        sub << num;
        sub >> str;

        long long cnt = 0;
        for(long long j = 0; j < s.length(); j++)
        {
            if(s[j] == str[cnt])++cnt;
        }
        if(cnt == str.length())
        {
            long long dif = s.length() - str.length();
            ans = min(ans, dif);
        }
    }
    if(ans == 1e15)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
