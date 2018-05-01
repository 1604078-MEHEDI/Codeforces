#include<bits/stdc++.h>
using namespace std;

int main()
{
    //int ar[100000];
    map< string,int>mp;

    int n;
    cin >> n;
    int p = n;
    int sum = 0;
    while(p--)
    {
        string str,s;

        cin >>s;
        sort(s.begin(),s.end());
        string::iterator it;
        it = unique(s.begin(),s.end());
        s.resize(distance(s.begin(),it));

        mp[s]++;
        if(mp[s] == 1)
        {
            sum += 1;
        }
    }
    cout<<sum<<endl;
}
