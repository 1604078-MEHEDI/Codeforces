#include<bits/stdc++.h>
using namespace std;

int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int a,b,x;
    cin >> a >> b >>x;
    int zero=0,one=0;
    if(a >= b)
    {
        for(int i = 1; i <= x; i++)
        {
            if(i % 2==0)
            {
                cout<<"1";
                one++;
            }
            else
            {
                cout<<"0";
                zero++;
            }
        }
        if(x%2==0)
        {
            for(int i = 0; i < b - one; i++)
                cout<<"1";
            for(int i = 0; i < a - zero; i++)
                cout<<"0";
        }
        else
        {
            for(int i = 0; i < a - zero; i++)
                cout<<"0";
            for(int i = 0; i < b - one; i++)
                cout<<"1";
        }
    }
    else
    {
        for(int i = 1; i <= x; i++)
        {
            if(i % 2==0)
            {
                cout<<"0";
                zero++;
            }
            else
            {
                cout<<"1";
                one++;
            }
        }
        if(x%2==0)
        {
            for(int i = 0; i < a - zero; i++)
                cout<<"0";
            for(int i = 0; i < b - one; i++)
                cout<<"1";
        }
        else
        {
            for(int i = 0; i < b - one; i++)
                cout<<"1";
            for(int i = 0; i < a - zero; i++)
                cout<<"0";
        }
    }
    return 0;

}
