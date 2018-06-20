#include<bits/stdc++.h>
using namespace std;
deque<char>str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n % 2 == 0)
    {
        while(s.size())
        {
            str.push_front(s[0]);
            s.erase(s.begin()+0);
            str.push_back(s[0]);
            s.erase(s.begin()+0);
        }
    }
    else
    {
        str.push_front(s[0]);
        s.erase(s.begin()+0);
        while(s.size())
        {
            str.push_front(s[0]);
            s.erase(s.begin()+0);
            str.push_back(s[0]);
            s.erase(s.begin()+0);
        }
    }
    deque<char>::iterator it;
    for(it = str.begin(); it != str.end(); it++)
    {
        cout<<*it;
    }

    return 0;
}
