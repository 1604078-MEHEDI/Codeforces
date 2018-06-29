#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n;
    cin >> n;
    string s = "ROYGBIV";
    string str = "ROYGBIV";
    for(int i = 7; i < n; i++){
            int j = 0;
            if(n - i <= 3){
                for(int k = 0; k <= 3-(n - i); k++){
                    if(str[k] == s[j])j++;
                }

            }
            while(1){
                if(str[i-1] == s[j] || str[i-2] == s[j] || str[i-3] == s[j]){
                    j++;
                }
                else break;
            }
    str +=s[j];
    }
    cout<<str<<endl;
    return 0;
}
