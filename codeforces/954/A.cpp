#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin>>n;
    cin>>str;
    int p = n;
    for(int i=0; i<n; i++)
    {
        if(str[i]=='U' && str[i+1]=='R' || str[i]=='R' && str[i+1]=='U')
            {
                p--;
                str[i+1] = 'D';
            }
    }
    cout<<p;
}
