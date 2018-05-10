
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char ck = 'a' ;
    int mv = 0,total_move = 0;
    for(int i = 0; i < s.length(); i++)
    {
        mv = abs(s[i] - ck);
        total_move += min(mv, 26-mv);
        ck = s[i];
    }

    cout<<total_move<<"\n";
    return 0;
}
