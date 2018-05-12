#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    map<char, int>mp;

    getline(cin , s);

    for(int i = 1; i < s.length()- 1; i++)
    {
        if(s[i] == ' ' || s[i] == ',')continue;
        mp[s[i]]++;
    }
    cout<<mp.size()<<endl;
    return 0;
}
