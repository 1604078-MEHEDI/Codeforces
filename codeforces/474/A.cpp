#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    st = "qwertyuiopasdfghjkl;zxcvbnm,./";

    char c;
    cin >> c;
    string s;
    cin >>s;
    if(c == 'R')
    {

        for(int i = 0; i < s.size(); i++)
        {
            for(int x = 0; x < st.size(); x++)
            {
                if(st[x] == s[i])
                {
                    cout<<st[x-1];
                    break;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < s.size(); i++)
        {
            for(int x = 0; x < st.size(); x++)
            {
                if(st[x] == s[i])
                {
                    cout<<st[x+1];
                    break;
                }
            }
        }
    }
}
