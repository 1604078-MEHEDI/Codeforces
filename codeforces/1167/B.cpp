#include<bits/stdc++.h>
using namespace std;
int reply[5];
int a[6] = {4, 8, 15, 16, 23, 42};

bool ok()
{
    for(int i = 0; i < 4; i++)
    {
        if(a[0] * a[i+1] != reply[i]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "? 1 2"<<endl;
    cout.flush();
    cin >> reply[0];

    cout << "? 1 3"<<endl;
    cout.flush();
    cin >> reply[1];

    cout << "? 1 4"<<endl;
    cout.flush();
    cin >> reply[2];

    cout << "? 1 5"<<endl;
    cout.flush();
    cin >> reply[3];

    do
    {
        if(ok()) break;
    }
    while(next_permutation(a, a+6));

    cout << "!";
    for(int i = 0; i < 6; i++) cout << " "<<a[i];
    cout << endl;
    cout.flush();

    return 0;
}
