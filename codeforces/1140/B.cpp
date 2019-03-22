#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int rgt = 0, lft = 0;
        int les = 0, gr = 0;
        for(int i = n - 1; i >=0 ; i--){
            if(s[i] == '<'){
                lft = i;
                break;
            }
            else gr++;
        }
        for(int i =0; i < n; i++){

            if(s[i] == '>'){
                rgt= i;
                break;
            }
            else les++;
        }
        cout << min(les, gr)<<endl;
    }
    return 0;
}
