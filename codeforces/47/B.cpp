#include<bits/stdc++.h>
using namespace std;
//vector<pair<char, int> > vp;
map<char, int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    mp['A'] = 0;
    mp['B'] = 0;
    mp['C'] = 0;
    for(int i = 0; i < 3; i++){
        string s;
        cin >> s;
        if(s[1] == '>'){
            mp[s[0]]++;

        }
        if(s[1] == '<')
            mp[s[2]]++;
    }
    map<char, int>:: iterator it;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it->second > 2){
            cout<<"Impossible\n";
            return 0;
        }
        if(it->second == 2)str[2] = it->first;
        if(it->second == 1)str[1] = it->first;
    }
    if(mp['A'] == 0)cout<<"A"<<str[1]<<str[2];
   else if(mp['B'] == 0)cout<<"B"<<str[1]<<str[2];
    else if(mp['C'] == 0)cout<<"C"<<str[1]<<str[2];
    else cout<<"Impossible\n";
    return 0;

}
