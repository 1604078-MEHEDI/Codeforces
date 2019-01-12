#include<bits/stdc++.h>
using namespace std;
vector< pair< pair<int, int>, int> > v;
int ans[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int x,y;
            cin >> x >> y;
            v.push_back( { {x,y}, i});
            ans[i] = 0;
        }
        sort(v.begin(), v.end());
        int Y = v[0].first.second;
         int idx = v[0].second;
         ans[idx] = 1;
         int flag = 0;
        for(int i = 1; i < n; i++)
        {
         //  cout << v[i].first.first << " "<<v[i].first.second << " "<<v[i].second<<endl;
            int X = v[i].first.first;
            if(Y >= X)
            {
                 idx = v[i].second;
                ans[idx] = 1;
                 Y =  max(v[i].first.second, Y);
            }
            else
            {
               // cout << "Enter-------\n";
                flag = 1;
              //  break;
            }
        }
        v.clear();
        if(flag){
        for(int i = 0; i < n; i++){
            if(ans[i] == 1)cout << "1 ";
            else cout << "2 ";
        }
        cout << endl;
        }
        else{
            cout << "-1"<<endl;
        }
    }

    return 0;
}
