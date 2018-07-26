#include<bits/stdc++.h>
using namespace std;

map<char, int>m;
void value ()
{
    char c = 'a';
    for(int i = 1; i <= 26; i++)
    {
        m[c] = i;
        c++;
    }
}
int main()
{
    value();
    int n,k;
    cin >> n >>k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    //cout<<s<<endl;
    int sum = 0,cnt=0,x=0,y=0;
    for(int i = 0; i < s.size(); i++)
    {
        if(cnt==k)break;
        //cout<<x<<" "<<y<<" "<<sum<<endl;
        if(i > 0)
        {
            x = m[s[i]];
            int ck = x - y;
            if(ck > 1){
                sum += x;
                cnt++;
                y = x;
            }
        }
        else
        {
            sum += m[s[i]];
            cnt++;
            y = m[s[i]];
        }
    }
    if(cnt==k){
        cout<<sum<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}
