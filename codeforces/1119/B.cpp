#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    vector<int> v;
    for(int i = 0; i <n; i++)
    {
        int x;
        cin >> x;
      v.push_back(x);
      sort(v.rbegin(), v.rend());
      int res = 0;
      for(int i = 0; i < v.size(); i += 2){
        res += v[i];
        if(res > h){
            cout << v.size() - 1<<endl;
            return 0;
        }
      }
    }
    cout << v.size()<<endl;
    return 0;
}

