#include<bits/stdc++.h>
using namespace std;

int main()

{
    int a,b,n,i,count=0,p=0;
    cin>>a>>b;
    p = a;
    for(i=1;i<=a; i++)
    {
        p -=b;
        if(p>=0)
        {
            count++;
            a +=count;
            if(count>0)
            {
                p++;
                count--;
            }
        }
        else
        {
            cout<<a;
            return 0;
        }
    }
}
