#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n,a,b,count=0,test=0,result=0;
    cin>>n>>a>>b;
    string str;

    cin>>str;

    for(int i=0; i<n; i++)
    {
        if(str[i] == '.')count++;
    }
    if(count==0)
    {
        cout<<0;
        return 0;
    }
  //  if(a+b >= count)

    if(a>=b)
    {
        for(int i=0; i<n; i++)
        {
            if(str[i]=='*')
            {
                test=0;
                continue;
            }
            if(str[i]=='.' && a>0 && test==0)
            {
                a--;
                test++;
                result++;
            }
            else if(str[i]=='.' && b>0)
            {
                b--;
                test = 0;
                result++;
            }

            else
                test = 0;
        }
    }
    else
        {
        for(int i=0; i<n; i++)
        {
            if(str[i]=='*')
            {
                test=0;
                continue;
            }
            if(str[i]=='.' && b>0 && test==0)
            {
                b--;
                test++;
                result++;
            }
            else if(str[i]=='.' && a>0)
            {
                a--;
                test = 0;
                result++;
            }
    else
        test = 0;
        }
    }

    cout<<result;
}