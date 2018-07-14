#include<bits/stdc++.h>
using namespace std;
int a[123456];
queue<int>q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int n;
    cin >> n;
    int  mn = 1e9+1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++){
            if(a[i] == mn)continue;
        q.push(a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int test = 0;
        while(!q.empty()){
            test++;
            if(q.front() > a[i]){
                cnt++;
                q.pop();
                break;
            }
            else{
                q.pop();
            }
        }
    if(test == 0)break;
    }
    cout<<cnt<<endl;
    return 0;
}
