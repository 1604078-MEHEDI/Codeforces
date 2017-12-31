#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,count=0,p,m=0,x=0,y=0;
    cin>>n;
    p = n;
    while(n>=0)
    {
        if(n%7==0)
        {
            x++;
            for(i=1; i<=count; i++)
            {
                cout<<"4";
            }
            a = n/7;
            for(i=1; i<=a; i++)
            {
                cout<<"7";
                if(i==a)
                    return 0;
            }
        }
        else if(n==4)
        {
            y++;
            cout<<"4";
            if(count==0)return 0;
            for(i=1; i<=count+1; i++)
            {
                cout<<"4";
                if(i==count)
                    return 0;
            }
        }
        count++;
        n -=4;
    }
    if(x==0 || y==0)
    {
        cout<<"-1";
        return 0;
    }
}
