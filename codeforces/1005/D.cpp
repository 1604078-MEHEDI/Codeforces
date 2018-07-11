#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s;
    cin >> s;
    int sum=0,cnt=0,s1 = 0,ck=0;
    for(int i = 0; i < s.length(); i++)
    {
        int p = (s[i] - '0');
        sum += s[i] - '0';
        if(i < s.length()- 1)
        s1 = (s[i] - '0')+(s[i + 1] - '0');

        if(p % 3 == 0)
        {
           // s[i] = '0';
            cnt++;
            sum = 0;
            s1 = 0;
        }
        else if(sum % 3 == 0 && sum > 0)
        {
           // s[i] = '0';
          // cout<<sum<<endl;
            cnt++;
            sum = 0;
            s1 = 0;
        }
        else if(s1 % 3 == 0 && s1 >0)
        {
          //  s[i] = '0';
            cnt++;
           // cout<<s1<<endl;
            i++;
            sum = 0;
            s1 = 0;
        }
       // cout<<p<<" "<<sum<<" "<<s1<<" "<<cnt<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}
