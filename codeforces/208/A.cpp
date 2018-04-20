#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int wub=0,test=0;
    string str;
    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == 'W' && str[i+1]=='U' && str[i+2]=='B')
        {
            str[i] = 'm';
            str[i+1] = 'm';
            str[i+2] = 'm';
        }
    }

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='m')
        {
            if(test==0)continue;
            wub = 1;
        }
        else
        {
            if(wub == 1)
            {
                cout<<' ';
                wub = 0;
            }
                test = 1;
                cout<<str[i];
        }
    }
}
