#include<bits/stdc++.h>
#define LL long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
#define MAX 9000007
int ar[MAX];

int main()
{
   // IO
    string str;
    char s[101];
    int n;
    cin >> n;
    cin >> str;
    int k = 1;
    // int len = str.length();

    for(int i = 1; i < n; i++)
    {
        if(str[i] == '1')continue;
        else
            s[k++] = '0';
    }
    s[0] = '1';

    if(str == "0" && n == 1)
    {
        cout<<"0";
        return 0;
    }
   // cout<<k<<endl;
  // cout<<s;
    for(int i = 0; i < k; i++)
    {
        cout<<s[i];
    }
    return 0;
}
