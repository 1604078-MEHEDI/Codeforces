
#include<bits/stdc++.h>
using namespace std;
int a[123456],b[123456],m[123456];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n,x;
    cin >> n >> x;
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> m[i];
        a[m[i]]++;
        if(a[m[i]]>1)flag = 1;
    }
    int f1=0;
    if(flag == 1)
    {
        cout<<0<<endl;
        return 0;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            int p = m[i]&x;
            if(a[p]>0 && p != m[i])
            {
                cout<<1<<endl;
                return 0;
            }
            b[p]++;
            if(b[p]>1)f1=1;
        }
    }
    if(f1==1)
    {
        cout<<2<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return 0;
}
