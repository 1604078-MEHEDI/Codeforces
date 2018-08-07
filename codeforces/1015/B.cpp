#include<bits/stdc++.h>
using namespace std;
map<char,int>c1,c2;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1 >> s2;
    if(s1 == s2)
    {
        cout<<"0";
        return 0;
    }
    for(int i =0; i< n; i++)
    {
        c1[s1[i]]++;
        c2[s2[i]]++;
    }
    char c = 'a';
    for( int i =0; i <26; i++)
    {

        if(c1[c] ==c2[c])
        {
            c++;
            continue;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    char s;
    // cin >> s;
    //  cout<<s1.find(s)<<endl;
    vector<int>v;
    int i = 0,pos=0;
    while(i<n)
    {
        if(s1[i] == s2[i]){
            i++;
            continue;
        }
        s = s2[i];
        for(int j =i+1; j < n; j++){
            if(s1[j] == s){pos = j;
            break;
            }
        }
        while(1){
            v.push_back(pos);
            swap(s1[pos], s1[pos-1]);
            pos--;
            if(pos == i)break;
        }

    }
    int limit = v.size();
    cout<<limit<<endl;
    for(int i =0; i < limit; i++)
    {
        cout<<v[i]<<" ";
    }
}
