#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i = 1; i <= 2*n; i++)
        cout<<" ";
    cout<<"0\n";

    for(int i = 1; i <= n*2 - 1; i++){
        if(i < n){
            for(int j = 1; j <= (n - i)*2; j++)
                cout<<" ";
        }
        else{
            for(int j = 1; j <= (i % n)*2; j++)
                cout<<" ";
        }

        if(i < n){
            for(int j = 0; j <= i % n; j++)
                cout << j << " ";
            for(int j = (i % n) - 1; j > 0; j--)
                cout << j << " ";
            cout << 0;
        }
        else if(i > n){
            for(int j = 0; j <= n - (i - n); j++)
                cout<<j<< " ";
            for(int j = (n - (i - n)) - 1; j > 0; j--)
                cout << j << " ";
            cout  <<0;
        }
        else{
            for(int j = 0; j <= n; j++)
                cout<<j << " ";
            for(int j = n -1; j > 0; j--)
                cout<<j << " ";
            cout<<0;
        }
        cout<<endl;
    }
    for(int i = 1; i <= n*2; i++)
        cout<< " ";
    cout<<0<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    pattern(n);
    return 0;
}
