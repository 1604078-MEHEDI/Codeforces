#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int>mp;

    int n,cnt=0,res=0;
    cin >>n;
    string s;
    cin >>s;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'x')
        {
            cnt++;
            if(cnt >= 3)res++;
        }
        else
        {
            cnt = 0;
        }
    }
    cout<<res<<endl;
    return 0;
}
