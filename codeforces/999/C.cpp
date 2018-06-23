#include<bits/stdc++.h>
using namespace std;
queue<char>s,res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s.push(c);
    }
    char ck = 'a';
    int t = 0;
    while(k)
    {
        while(s.size())
        {
            if(s.front() == ck)
            {
                s.pop();
                t++;
                if(t >= k)
                {
                    while(!res.empty())
                    {
                        cout<<res.front();
                        res.pop();
                    }
                        while(s.size())
                        {
                            cout<<s.front();
                            s.pop();
                        }
                        return 0;
                }
                }
            else
            {
                res.push(s.front());
                s.pop();
            }
        }
        while(!res.empty())
        {
            s.push(res.front());
            res.pop();
        }
        ck++;
        if(ck >= 'z')ck = 'z';
    }
}
