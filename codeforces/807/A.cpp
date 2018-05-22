#include<bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0),cin.tie(0);

int main()
{
    IO
    int a,b,n;

    cin >> n;
    int ck = 0,cnt = 0, p= 99999;
    for(int i = 0; i < n; i++)
    {
        cin >>a>>b;
        if(a != b && ck == 0)
        {
            ck = 1;
        }

        if(p >=  a)
        {
            cnt++;
            p = a;
        }
    }

    if(ck == 1)
    {
        cout<<"rated\n";
    }
    else if(cnt == n)
    {
        cout<<"maybe\n";
    }
    else
    {
        cout<<"unrated\n";
    }
    return 0;
}
