#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    int n;
    map<string, string>m;
    m["purple"] = "Power";
    m["green"] = "Time";
    m["blue"] = "Space";
    m["orange"] = "Soul";
    m["red"] = "Reality";
    m["yellow"] = "Mind";
    cin >>n;
    int p = n;
    while(n--)
    {
        string s;
        cin >>s;
        m[s] = "null";
    }
    map<string, string>:: iterator it;
    cout<<6-p<<endl;
    for( it = m.begin(); it != m.end(); it++)
    {
        if(it->second == "null")continue;
        cout<<it->second<<endl;
    }
    return 0;
}
