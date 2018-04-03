#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0;
    string str;
    char c;

    map<char, int>m;

    cin>>str;

    int len = str.length();

    for(int i=0; i<len; i++)
    {
        c = str[i];
        m[c]++;
        if(m[c]>1)
        {
           // len--;
            count++;
            m[c]--;
        }
    }
    int p = len - count;
    //cout<<len-count<<endl;
    if(p%2==0)
    cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";
}
