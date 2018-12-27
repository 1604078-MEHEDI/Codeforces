#include<bits/stdc++.h>
using namespace std;
 priority_queue<int>PQ;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    int cnt = __builtin_popcount(n);
    //cout << cnt << endl;
    if(k > n || k < cnt)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
        int ts = 0;
        for(int i = 0; i < 31; i++)
        {
            if(n & (1 << i))
            {
                ts++;
                //cout << (1 << i)<< " ";
                PQ.push(1 << i);
                if(ts == cnt)break;
            }
        }
    if(cnt < k)
    {
        int ext = k - cnt;
        for(int i = 0; i < ext; i++){
            int x = PQ.top();
            PQ.pop();
            PQ.push(x/2);
            PQ.push(x/2);
        }
    }
    while(!PQ.empty()){
        cout << PQ.top() << " ";
        PQ.pop();
    }
    return 0;
}

