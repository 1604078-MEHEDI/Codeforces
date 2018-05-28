#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    string s;
    cin >> s;

    string t = s;
    reverse(t.begin(), t.end());

    if(s != t)
        cout<<s.length()<<"\n";
    else if(s == string(s.length(), s[0]))
        cout<<"0\n";
    else
        cout<<s.length() - 1<<"\n";
    return 0;
}
