#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,ans=0,count=0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>a;

        if(a > -1)
        {
           count +=a;
        }

        else if(a== -1)
        {
            if(count>0)
            {
                count--;
                continue;
            }
            else
                ans++;
        }
    }
        cout<<ans<<endl;
}
