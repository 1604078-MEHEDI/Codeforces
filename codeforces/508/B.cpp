#include<bits/stdc++.h>
using namespace std;

int main()
{
    int len,cnt=0;
    string str,s,stc,st="1",ss;

    cin>>str;
    //  s  = str;
    //cout<<s<<endl;
    len = str.length();


    for(int i = len - 1; i >= 0; i--)
    {
        if(str[i] == '0' || str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '8')
        {

            if(str[len - 1] < str[i])
            {
                s = str;
                s[len - 1] = str[i];
                s[i] = str[len - 1];
                break;
            }
        }
        else cnt++;
    }
    if(cnt == len){
        printf("-1\n");
        return 0;
    }
   for(int i = 0; i < len; i++)
    {
        if(str[i] == '0' || str[i] == '2' || str[i] == '4' || str[i] == '6' || str[i] == '8')
        {

            if(str[len - 1] >= str[i])
            {
                ss = str;
                ss[len - 1] = str[i];
                ss[i] = str[len - 1];
                break;
            }
        }
    }
    if((s.compare(ss)) > 0)
        cout<<s<<"\n";
        else
            cout<<ss<<"\n";
    return 0;
}
