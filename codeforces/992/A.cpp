#include<bits/stdc++.h>
using namespace std;
set<int>st;
int ar[123456];

int main()
{
  //  cout<<(3 ^ (-3))<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if(ar[i] != 0){
        st.insert(ar[i]);
        }
    }
    cout<<st.size()<<endl;

}
