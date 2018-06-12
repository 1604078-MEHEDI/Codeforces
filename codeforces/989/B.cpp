#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long
//const int mx = 2000 * 2000;
//char s[mx];

int main()
{
    IO
    int n,p;
    cin >> n >> p;
    //for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    //}
    int cnt  = 0;
    for(int i = 0; i < (n - p); i++)
    {
        if(s[i] == '.')continue;
        if(s[i] == s[i+p])cnt++;
    }
    if(cnt  == (n - p))
    {
        cout<<"No\n";
        return 0;
    }
    else
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '.')
            {
                if(i+p < n)
                {
                    if(s[i+p] == '1')s[i] = '0';
                    else if(s[i+p] == '0')s[i] = '1';
                    else
                    {
                        s[i] = '1';
                        s[i+p] = '0';
                    }
                }
                else if(i-p >= 0)
                {
                    if(s[i-p] == '1')s[i] = '0';
                    else if(s[i-p] == '0')s[i] = '1';
                    else
                    {
                        s[i] = '1';
                        s[i-p] = '0';
                    }
                }
                else
                    s[i] = '0';
            }
        }
 cout<<s;
//    for(int i = 0; i < n; i++)
//    {
//        cout<<s[i];
//    }
    return 0;
}
