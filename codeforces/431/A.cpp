#include<bits/stdc++.h>
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    int a[5],sum = 0;
    for(int i = 1; i <= 4; i++)
        scanf("%d", &a[i]);

    string str;

    cin >> str;
   // scanf("%s", str);

    for(int i = 0; i < str.length(); i++)
    {
        sum += a[str[i]- '0' ] ;
    }

//    cout<<sum<<"\n";
printf("%d\n", sum);
    return 0;
}
