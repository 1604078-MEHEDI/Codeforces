#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    string s;
    cin >> s;
    int cnt  = 0;
    int a = 0, b = 0, c = 0,ck=0;
    for(int i = 0; i < s.size(); i++)
    {

        if(s[i] == 'A')
        {
            if(( s[i + 1] == 'C' && s[i-1] == 'B' ) || ( s[i + 1] == 'B' && s[i-1] == 'C' ))
            {
                cout<<"Yes\n";
                return 0;
            }
        }
        if(s[i] == 'B')
        {
             if(( s[i + 1] == 'C' && s[i-1] == 'A' ) || ( s[i + 1] == 'A' && s[i-1] == 'C' ))
            {
                cout<<"Yes\n";
                return 0;
            }
        }
        if(s[i] == 'C')
        {
             if(( s[i + 1] == 'A' && s[i-1] == 'B' ) || ( s[i + 1] == 'B' && s[i-1] == 'A' ))
        {
            cout<<"Yes\n";
            return 0;
        }
    }
    }
    cout<<"No\n";
    return 0;
}
