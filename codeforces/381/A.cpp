#include<bits/stdc++.h>
using namespace std;

deque <int> dq;
int ans[2];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >>a;
        dq.push_back(a);
    }

    int k = 0;
    int sareja = 0, dima = 0,mx;
    while(!dq.empty())
    {
        if(dq.back() > dq.front() )
        {
             ans[k] += dq.back();
             dq.pop_back();
        }
        else
        {
            ans[k] += dq.front();
            dq.pop_front();
        }
        k = (k + 1)%2;
    }

    cout<<ans[0] << " "<<ans[1]<<endl;
    return 0;
}
