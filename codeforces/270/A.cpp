#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,m,a,count,x,p=1000;
    cin>>m;
    for(i=1; i<=m; i++)
    {
        count=0;
        cin>>a;
        for(n=3; n<=p; n++)
        {
            x = (2*n - 4)*90;
          //  p = x;
            if((n*a)==x)
            {
                count++;
                cout<<"YES"<<endl;
                break;
            }
        }
        if(count==0)
        {
            cout<<"NO"<<endl;
        }
     //   cout<<x;
    }
}
