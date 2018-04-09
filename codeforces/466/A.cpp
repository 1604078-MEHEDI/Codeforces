#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b,count=0,ar[10],s,p;
    for(int i=0; i<10; i++)ar[i] = 9999999;
    cin>>n>>m>>a>>b;

    ar[0] = n*a;
    if(n%m==0)ar[1] = (n/m)*b;
    else ar[2] = ((n/m)+1)*b;
    if(m>=n)ar[3] = b;
    //cout<<z<<endl;

    while(n>0)
    {
        n --;
        count++;
        s = count*a;

        if(n%m==0)
        {
            p = (n/m)*b;

            ar[4] = s + p;
            break;
        }
    }
    sort(ar, ar+5);
//for(int i=0; i<5; i++)
    cout<<ar[0];
}
