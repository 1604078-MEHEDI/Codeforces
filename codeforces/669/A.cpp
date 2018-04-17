#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n,count=0,t1=0,t2=0;
    cin>>n;

    while(n>0)
    {
        if(n >= 2 && t2==0)
        {
            n -=2;
            count++;
            t2 = 1;
            t1 = 0;
        }
        else if(n >= 1 && t1==0)
        {
            n -=1;
            count++;
            t1 = 1;
            t2 = 0;
        }
        else
        {
            count++;
            break;
        }
    }

    cout<<count;
    return 0;
}
