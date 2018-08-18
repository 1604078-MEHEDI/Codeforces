#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,q;
    cin >> n >> q;
    long long first = ((n*n)+2-1)/2;
    //cout<<first<<endl;
    long long odd = (n+2-1)/2;
    long long even = n - odd;
    //cout<<odd<<" "<<even<<endl;
    if(n % 2 == 0)
    {
        while(q--)
        {
            long long x,y;
            cin >> x >> y;
            long long ans = (x+y);
            if(ans % 2 == 0)
            {
                long long num = (x-1)*even + (y+2-1)/2;
                cout<<num<<endl;
            }
            else
            {
                long long num = (x-1)*odd + (y+2-1)/2 + first;
                cout<<num<<endl;
            }
        }
    }
    else
    {
        while(q--)
        {
            long long x,y;
            cin >> x >> y;
            long long ans = (x+y);
            if(x % 2 != 0)
            {
                if(ans % 2 == 0)
                {
                    long long num = (x-1)*even + (y+2-1)/2 + x/2;
                    cout<<num<<endl;
                }
                else
                {
                    long long num = (x-1)*even + (y+2-1)/2 + first + x/2;
                    cout<<num<<endl;
                }
            }
            else
            {
                if(ans % 2 == 0)
                {
                    long long num = (x-1)*even + (y+2-1)/2 + x/2;
                    cout<<num<<endl;
                }
                else
                {
                    long long num = (x-1)*odd + (y+2-1)/2 + first - x/2;
                    cout<<num<<endl;
                }
            }
        }
    }
    }
