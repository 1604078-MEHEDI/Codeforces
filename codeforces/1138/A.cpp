#include<bits/stdc++.h>
using namespace std;
#define ll long long

int t[100005];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n, ans = 0, one = 0, two = 0, cnt = 0;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>t[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(t[i]==2)
        {
            two++;
            if(one > 0)
            {
                ans = min(one,two);
            }
        }
        if(t[i]==1)
        {
            one = 0;
            for(int j = i; j < n; j++)
            {
                if(t[j]==2)
                {
                    i = j-1;
                    break;
                }
                one++;
            }
            ans = min(one,two);
            two = 0;
        }
        cnt = max(ans,cnt);
    }

    cout<<cnt*2<<endl;

    return 0;
}
