#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    IO
    string s;
    cin >> s;
    if(s[0] == 'a' && (s[1] == '8'|| s[1] == '1'))
        cout<<3<<endl;
    else if (s[0] == 'h' && (s[1] == '8' || s[1] == '1'))
        cout<<3<<endl;
    else if(s[0] > 'a' && s[0] < 'h')
    {
        if(s[1] > '1' && s[1] < '8')
            cout<<8<<endl;
        else
            cout<<5<<endl;
    }
    else
        cout<<5<<endl;
    return 0;
}
