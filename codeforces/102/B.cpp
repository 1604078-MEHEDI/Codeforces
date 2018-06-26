#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n,s;
    cin >> n;
    int cnt = 0;
    while(1)
    {
        if(n.size()==1)
        {
            cout<<cnt<<endl;
            return 0;
        }
        cnt++;
        int sum = 0;
        for(int i = 0; i < n.size(); i++)
        {
            sum += n[i] - '0';
        }
       // int i = 123;
       // std::string out_string;
       stringstream ss;
        ss << sum;
        n = ss.str();
    }
    return 0;
}
