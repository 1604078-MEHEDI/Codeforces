#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k2,k3,k5,k6,ar[5],extra_two,result;

    cin>>k2>>k3>>k5>>k6;

    ar[0] = k2;
    ar[1] = k5;
    ar[2] = k6;
    sort(ar, ar+3);

    int mini = ar[0];

    result = mini*256;

      extra_two = k2 - mini;

     if(extra_two > 0)
     {
         if(extra_two >= k3)
         {
             result += k3*32;
             cout<<result<<endl;
             return 0;
         }
         else
         {
             result += extra_two*32;
             cout<<result<<endl;
             return 0;
         }
     }
     else

     {
         cout<<result<<endl;
         return 0;
     }
}
