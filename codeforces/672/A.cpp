#include<bits/stdc++.h>
using namespace std;

int ar[10000000];

void task()
{
    int i=1;
    for(int j = 1; j<=1001; j++)
    {
        int p;
        p = j;
        if(p >= 1000)
        {
            int x,y,z,w;
            x = p/1000;
            ar[i++] = x;
            y =p/100;
            y = y%10;
            ar[i++] = y;
            z = p/10;
            z = z%10;
            ar[i++] = z;
            w = p%10;
            ar[i++] = w;
        }
    else if(p >= 100 && p < 1000)
    {
        int x,y,z,w;
            x = p/100;
            ar[i++] = x;
            y =p/10;
            y = y%10;
            ar[i++] = y;
            z = p%10;
            ar[i++] = z;
           // cout<<x<<" "<<y<<" "<<z<<" __p "<<p<<endl;

    }

    else if(p >= 10 && p < 100)
    {
        int x,y;
        x = p/10;
        ar[i++] = x;
        y = p%10;
        ar[i++] = y;
    }
    else
    {
        //int x;
       // x = p%10;
        ar[i++] = p;
    }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;
    task();
   // for(int i=1; i<=1000; i++)
    //{
     //  cout<<"Case "<<i<<" : "<<ar[i]<<endl;
    //}
    //cout<<endl;

    cout<<ar[n]<<"\n";
    return 0;

}
