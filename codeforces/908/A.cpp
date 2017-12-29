#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,len,count=0;
    string s;
    cin>>s;
    len = s.length();
    for(i=0; i<len; i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]== 'i' || s[i]=='o' || s[i]=='u' || s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9' )
        {
            count++;
        }
    }
    cout<<count;
}
