#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[4],sum = 0;

    cin >> a[0] >> a[1] >> a[2] >> a[3];

    string str;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '1') sum += a[0];
        else if(str[i] == '2') sum += a[1];
        else if(str[i] == '3') sum += a[2];
        else if(str[i] == '4') sum += a[3];
    }

    cout<<sum<<"\n";
    return 0;
}
