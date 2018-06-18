#include<bits/stdc++.h>
using namespace std;
//#define long long  long long
vector<pair <long long, long long> >vp,V;
long long a[123456];
long long cum_sum[123456],min_sum[123456];
map<int, long long>res,pk;
priority_queue<long long>pq;
stack<long long>st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        long long b;
        cin >> b;
        vp.push_back(make_pair(a[i], b));
        V.push_back(make_pair(a[i], b));
    }
    sort(vp.begin(), vp.end());
    long long sum = 0,mn = 1e10,m_sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(i > 0)
        pq.push(vp[i - 1].second);
        int test = k;
        sum = 0;
        //cout<<"NewLine"<<endl;
        while(pq.size() && test)
        {
            sum += pq.top();
           // cout<<sum<<endl;
            st.push(pq.top());
            pq.pop();
            test--;
        }
        while(!st.empty()){
            pq.push(st.top());
                st.pop();
        }
        // cout<<" -- "<<sum<<endl;
        if(k == 0)
            cum_sum[i] = vp[i].second;
        else
            cum_sum[i] = sum + vp[i].second;
        res[vp[i].first] = cum_sum[i] ;
    }
    for(int i = 0; i < n; i++)
    {
        cout<<res[V[i].first]<<" ";
    }
}
