#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c)
{
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main()
{
    int len;
    string str;
    cin>>str;

    len = str.length();

    for(int i=0; i<len; i++)
    {
        if(str[i]>= 'A' && str[i]<='Z')
            str[i] = str[i] + 32;
        if(!isVowel(str[i]))
            printf(".%c", str[i]);
    }


}
