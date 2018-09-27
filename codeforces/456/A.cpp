#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int flag = 0;
    for(int i = 0; i <n; i++)
    {
        int x,y;
        cin >>x >>y;
        if(y>x)flag =1;
    }
    if(flag)cout<<"Happy Alex\n";
    else cout<<"Poor Alex\n";
    return 0;
}
