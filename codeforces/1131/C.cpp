#include<bits/stdc++.h>
using namespace std;
 int a[1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > PQ;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        PQ.push(x);
    }
    int i = 1, k = n;
    while(!PQ.empty()){
        int x = PQ.top();
        PQ.pop();
     if(PQ.size() == 0){
              a[i] = x;
            break;
        }
        int y = PQ.top();
        PQ.pop();
        a[i++] = x;
        a[k--] = y;
        if(PQ.size() == 0) break;
    }
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
