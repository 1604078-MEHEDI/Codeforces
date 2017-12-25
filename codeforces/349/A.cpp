#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,count=0,a,p=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        if(a==25)
        {
            count++;
        }
        if(a==50)
        {
            p++;
            if(count>0)
            {
                count--;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
        if(a==100)
        {
            if(count>0 && p>0)
            {
                count --;
                p--;
            }
            else if(count>2)
            {
                count -=3;
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
