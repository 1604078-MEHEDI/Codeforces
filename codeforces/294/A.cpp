#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ar[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> ar[i];
    }
    int m;
    cin >> m;

    for(int i = 1; i <= m; i++)
    {
        int x,y;
        cin >> x >> y;
        if(x + 1 <= n) ar[x+1] = ar[x+1] + (ar[x] - y);
        if(x - 1 > 0) ar[x-1] += y - 1;
        ar[x] = 0;
         //for(int i = 1; i <= n; i++)
        //cout<<ar[i]<<" ";
     //   cout<<endl;
    }

    for(int i = 1; i <= n; i++)
        cout<<ar[i]<<"\n";
    return 0;
}
