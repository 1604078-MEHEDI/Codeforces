#include<bits/stdc++.h>
using namespace std;

int main()
{
    pair < int, int >hm;
    int n,s,h[101],m[101],r1 = 0,r2 = 0 ,cnt=0;
    cin >> n >> s;

    for(int i = 0; i< n ; i++)
    {
        cin >>h[i] >>m[i];
    }
    int k =0;
    int temp = h[0]*60+m[0];
    for(int i =0 ; i<n; i++)
    {
        if(temp > s && m[n-1] == 59)
        {
            cout<<"0"<<"1"<<endl;
        }
        else if(temp > s)
        {
            cout<<"0"<<" "<<"0"<<endl;
            return 0;
        }
    int y =  (h[i+1]*60 +m[i+1]);
    int x  = (h[i] *60 + m[i]);
    int p = y - x;
    //   cout<<y<<" "<<x<<" "<<p<<endl;

    if(p > (2*s)+1)
    {
        cnt++;
        int t = x + (s+1);
        //cout<<t<<endl;
        r2 = t%60;
        //cout<<r1<<endl;
        r1 = t/60;
        break;
    }
}
if(cnt == 0)
{
    int t = (h[n-1]*60+m[n-1]) + (s+1);
     r2 = t%60;
     r1 = t/60;
}
cout<<r1<<" "<<r2<<endl;
}
