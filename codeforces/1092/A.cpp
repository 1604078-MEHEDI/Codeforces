#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >>k;
        char c = 'a';
        int cnt = 0;
        for(int i = 1; i <= n; i++){
                cout << c;
                if(cnt+1 >= k)
                {
                    c = 'a';
                    cnt = 0;
                }
                else{
                    cnt++;
                 c++;
                }
        }
        cout << endl;
    }
    return 0;
}
