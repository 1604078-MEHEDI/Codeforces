#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,ck = 0;
    cin >> t;
    string str[1001],s;
    for(int i = 0; i < t; i++)
    {
        cin >> s;
        if(s[0] =='O' && s[1] == 'O' && ck == 0)
        {
            s[0] = '+';
            s[1] = '+';
            ck = 1;
        }
        else if(s[3] =='O' && s[4] == 'O' && ck == 0)
        {
            s[3] = '+';
            s[4] = '+';
            ck = 1;
        }
        str[i] = s;
    }
    if(ck > 0)
    {
        cout<<"YES\n";
        for(int i = 0; i < t; i++)
        {
            cout<<str[i]<<endl;
        }
    }
    else
        cout<<"NO\n";
    return 0;
}
