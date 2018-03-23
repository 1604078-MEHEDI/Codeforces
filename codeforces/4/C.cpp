#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int n,i;
    string st;
    map<string, int>m;
    cin>>n;
    while(n--)
    {
        cin>>st;
        m[st]++;
        if(m[st]==1)cout<<"OK"<<endl;
        else
            cout<<st<<m[st]-1<<endl;
    }

}
