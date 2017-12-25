#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,a,s,i,c=0,d=0,p;
    cin>>n;
     a = 4;
     s = n - a;
     for(i=1; i<=n; i++)
     {
         for(i=2; i<a; i++)
         {
             if(a%i==0)
             {
                 c++;
             }
         }
        for(i=2; i<s; i++)
        {
            //p = s/i;
          //  cout<<p<<" ";
            if(s%i==0)
            {
                d++;
            }
        }
        if(c>=1 && d>=1)
        {
           // cout<<endl;
            cout<<a<<" "<<s;
            return 0;
        }
         else
         {
             a++;
             s--;
             c=0;
             d=0;
         }
       //  cout<<"S "<<s<<" A "<<a<<endl;
     }
}
