#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int p=0,q=0,a,b;
    int col,row,cnt=0;
    for(int i=1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char c;
            cin >> c;
            if(c == 'B'){
                cnt++;
                a = i;
                b = j;
            }
            if(c == 'B' && p == 0){
                row = i;
                col = j;
                p++;
            }
        }
    }
    if(cnt == 1){
        cout<<a<<" "<<b<<endl;
    }
    else{
        int black = sqrt(cnt);
        int ans = (black/2);
        cout<<row+ans<<" "<<col + ans<<endl;
    }
    return 0;
}
