///Help from --> win11905 ):-///
#include<bits/stdc++.h>
using namespace std;

char ch[55][55];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    a--, b--, c--, d--;
    cout<<"40 50\n";
    for(int i = 1; i <= 10; i++) for(int j = 1; j <= 50; j++) ch[i][j] = 'a';
    for(int i = 11; i <= 20; i++) for(int j = 1; j <= 50; j++) ch[i][j] = 'b';
    for(int i = 21; i <= 30; i++) for(int j = 1; j <= 50; j++) ch[i][j] = 'c';
    for(int i = 31; i <= 40; i++) for(int j = 1; j <= 50; j++) ch[i][j] = 'd';

    for(int i = 1; i <= 10; i += 2) for(int j = 1; j <= 50; j += 2){
        if(b){
            b--;
            ch[i][j] = 'b';
        }
    }
    for(int i = 11; i <= 20; i += 2) for(int j = 1; j <= 50; j += 2){
        if(c){
            c--;
            ch[i][j] = 'c';
        }
    }
    for(int i = 21; i <= 30; i += 2) for(int j = 1; j <= 50; j += 2){
        if(d){
            d--;
            ch[i][j] = 'd';
        }
    }
    for(int i = 31; i <= 40; i += 2) for(int j = 1; j <= 50; j += 2){
        if(a){
            a--;
            ch[i][j] = 'a';
        }
    }
    for(int i = 1; i <= 40; i++)
        cout<<ch[i]+1<<endl;
    return 0;
}
