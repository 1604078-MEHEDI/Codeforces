#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,a,count=0,c=0,ar[101],ck=0,m=0;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        ar[i] = a;
        if(a==0)
        {
            ck++;
            if(ck>m)
            {
                m = ck;
            }
            c++;
        }
        if(a==1)
        {
            ck--;
            if(ck<=0)
            {
                ck = 0;
            }
            count++;
        }
    }
    if(c==0)
    {
        cout<<count-1;
        return 0;
    }
  //  cout<<m<<endl;
   // cout<<c<<endl;
    cout<<count+m;
}
