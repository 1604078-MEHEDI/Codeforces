#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long
vector<pair<int, int> > vp;

double sq(double a, double b)
{
    return sqrt((a*a) + (b * b));
}
int main()
{
    IO
    int n,k,x,y;
    double res;
    cin >>n >>k;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >>b;
        if(i > 0)
        {
            res += sq((a - x), (b - y));
        }
        x = a;
        y = b;
        //vp.push_back(make_pair(a, b));
    }
    double ans = (res*k)/50;
    cout<<fixed<<setprecision(9)<<ans<<endl;
    return 0;
}
