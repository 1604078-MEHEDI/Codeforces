#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=0,b=0,c=0;
    string str;

    cin>>str;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='a')
        {
            a++;
        }
       else  if(str[i]=='b')
        {
            b++;
        }
        else if(str[i]=='c')
        {
            c++;
        }
    }

    for(int j=0; j<a; j++)
        {
            if(str[j]!='a')
            {
                cout<<"NO";
                return 0;
            }
        }
        for(int j=a; j<a+b; j++)
        {
            if(str[j]!='b')
            {
                cout<<"NO";
                return 0;
            }
        }
        for(int j=a+b; j<a+b+c; j++)
        {
            if(str[j]!='c')
            {
                cout<<"NO";
                return 0;
            }
        }

        if((a==c || b==c) && a>=1 && b>=1)
        {
            cout<<"YES";
            return 0;
        }
        else
            cout<<"NO";
}
