#include<bits/stdc++.h>
using namespace std;
//vector< pair<int, int> >v;
//vector<int>v;
int a[12345];
queue<int>q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
            int x;
        cin >> x;
        q.push(x);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(q.empty())break;
        if(q.front() >= a[i]){
            cnt++;
            q.pop();
    }
    }
    cout<<cnt<<endl;
    return 0;
}
