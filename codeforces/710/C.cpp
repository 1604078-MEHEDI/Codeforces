#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    int n;
    cin >> n;
    int even = 2, odd = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < n; j++)
        {
            if(min(i, n - i - 1) + min(j, n - j - 1) >= n/2)
            {
                cout<<odd<<" ";
                odd += 2;
            }
            else
            {
                cout<<even<<" ";
                even += 2;
            }
        }
        cout<<endl;
    }
}
