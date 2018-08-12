#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,h,a,b,k;
    cin >> n >> h >> a >> b >> k;
    while(k--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2)
        {
            cout<<abs(y1 - y2)<<endl;
        }
        else
        {
            if(y1 >= a && y1 <= b)
            {
                int p = abs(x1 - x2) + abs(y1 - y2);
                cout<<p<<endl;
            }
            else
            {
                int lo = abs(y1 - a);
                int hi = abs(y1 - b);
                int p = lo + (abs(x1 - x2)) + abs(a - y2);
                int q = hi + (abs(x1 - x2)) + abs(b - y2);
                cout<<min(p,q)<<endl;
            }
        }
    }
    return 0;
}
