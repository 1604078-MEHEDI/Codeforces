
#include<bits/stdc++.h>
using namespace std;
//int ar[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;
    int l = max(s1.length(), s2.length());

    int cnt = 0;

    for(int i = 0; i < l ; i++){
        if((s1[i] == '0' && s1[i+1] == '0' && s2[i] == '0')){
            cnt++;
            s1[i] = 'X';
            s1[i+1] = 'X';
            s2[i] = 'X';
        }
        if (s1[i+1] == '0' && s2[i] == '0' && s2[i+1] == '0'){
            cnt++;
            s1[i + 1] = 'X';
            s2[i+1] = 'X';
            s2[i] = 'X';
        }
        if(s1[i] == '0' && s1[i+1] == '0' && s2[i+1] == '0') {
            cnt++;
            s1[i] = 'X';
            s1[i+1] = 'X';
            s2[i + 1] = 'X';
        }
        if (s1[i] == '0' && s2[i] == '0' && s2[i+1] == '0'){
            cnt++;
            s1[i] = 'X';
            s2[i+1] = 'X';
            s2[i] = 'X';
        }
    }

    //int cnt = c1 + c2;
    cout<<cnt<<endl;
    return 0;
}
