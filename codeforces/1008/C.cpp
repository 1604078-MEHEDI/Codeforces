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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        q.push(a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        while(!q.empty()){
            if(q.front() > a[i]){
                cnt++;
                q.pop();
                break;
            }
            else{
                q.pop();
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
