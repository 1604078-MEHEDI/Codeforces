#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p = n/4;
    if(n%4 != 0){
        cout<<"===\n";
        return 0;
    }
    int a=0,t=0,c=0,g=0,cnt=0;
    for(int i = 0; i <n; i++){
        if(s[i]== '?')cnt++;
        if(s[i] == 'A')a++;
        if(s[i] == 'T')t++;
        if(s[i] == 'G')g++;
        if(s[i] == 'C')c++;
    }
    if(a > p || t > p || g > p || c > p){
        cout<<"===\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '?'){
            if(p > a){
                s[i] = 'A';
                a++;
            }
            else if(p > t){
                s[i] = 'T';
                t++;
            }
            else if(p > g){
                s[i] = 'G';
                g++;
            }
            else if(p > c){
                s[i] = 'C';
                c++;
            }

        }
    }
    cout<<s<<endl;
    return 0;
}
