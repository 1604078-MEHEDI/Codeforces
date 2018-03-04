#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int,int> > vect;
    int ar[100000],ar1[100001],n,s,count=0;
    cin>>s>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i]>>ar1[i];
    }
    for(int i=0; i<n; i++)
    {
        vect.push_back(make_pair(ar[i],ar1[i]));
    }
    sort(vect.begin(), vect.end());
   /** for(int i=0; i<n; i++)
    {
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }**/
    for(int i=0; i<n; i++)
    {
        if(s>vect[i].first)
        {
            count++;
            s +=vect[i].second;
        }
        else
        {
            count=0;
            break;
        }
    }
    if(count>0)
    {
        cout<<"YES";
       // cout<<s;
    }
    else
    {
        cout<<"NO";
        //cout<<s;
    }
    return 0;
}
