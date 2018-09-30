#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
string str[1234];
void get()
{
    for(char c = 'a'; c <= 'z'; c++){
        str[cnt++] = c;
       // cout<<str[cnt-1]<<endl;
    }
    for(char c = 'a'; c <= 'z'; c++){
            string s;
            s += c;
        for(char x = 'a'; x <= 'z'; x++){
            s = c;
            s += x;
            str[cnt++] = s;
            //cout<<str[cnt-1]<<endl;
        }
    }
    return;
}

int main()
{
    get();
    int t;
    cin >> t;
    string s_string;
    for(int i = 0; i < t; i++){
        string a;
        cin >> a;
        s_string += "."+a;
    }
    //cout<<s_string<<endl;
    int len = s_string.length();
    for(int i = 0; i < cnt; i++){
        string x = str[i];
        //cout<<x<<endl;
        //int p = s_string.find(x);

        if(s_string.find(x) !=string::npos){
            continue;
        }
        else{
            cout<<x<<endl;
            break;
        }
    }
    return 0;
}
