#include<bits/stdc++.h>
using namespace std;

int main()
{
    map <char, int> mp;
    char c = 'a', ck = 'a';
    for(int i = 1; i <= 26; i++)
    {
       // cout<<c<<" ";
        mp[c] = i;
        c++;
    }
    string s;
    cin >> s;
    int mv = 0,total_move = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if ( mp[ck] > mp[s[i]])
        {
            mv = min( (mp[ck] - mp[s[i]] ), (mp[s[i]] - mp[ck] + 26) );
            ck = s[i];
            total_move += mv;
        }
        else
        {
             mv = min( (mp[s[i]] - mp[ck] ), (mp[ck] - mp[s[i]] + 26) );
             ck = s[i];
             total_move += mv;
        }
    }

    cout<<total_move<<"\n";
    return 0;
}
