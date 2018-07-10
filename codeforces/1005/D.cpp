#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cnt = 0, sum = 0, s1 = 0;
    string s;
    cin>>s;

    for(int i = 0; i < s.length(); i++)
    {
        int k = s[i] - '0';
        sum+=s[i]-'0';
        s1 = (s[i]-'0') + (s[i+1]-'0');
        if(k%3==0)
        {
            s[i] = '0';
            cnt++;
            sum = 0;
            s1 = 0;
        }
        else if(sum%3==0 && sum!=0)
        {
            s[i] = '0';
            cnt++;
            sum = 0;
            s1 = 0;
        }
        else if(s1%3==0 && s1!=0)
        {
            s[i] = '0';
            cnt++;
            i++;
            sum = 0;
            s1 = 0;
        }
    }

    cout<<cnt<<endl;

    return 0;
}
