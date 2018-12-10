#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int cnt = 0;
    cin >> s;
    int n = s.size();
    for(int i=0; i < n; i++)
    {
        if(s[i] == 'Q')
        {
            for(int j = i+1; j <n; j++)
            {
                if(s[j] == 'A')
                {
                    for(int k = j+1; k < n; k++)
                    {
                        if(s[k] == 'Q')cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
