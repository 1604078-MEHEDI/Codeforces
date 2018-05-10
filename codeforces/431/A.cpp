#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5],sum = 0;
    for(int i = 1; i <= 4; i++)
        cin >> a[i];

    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        sum += a[str[i]- '0' ] ;
    }

    cout<<sum<<"\n";
    return 0;
}
