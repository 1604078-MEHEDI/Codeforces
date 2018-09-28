#include<bits/stdc++.h>
using namespace std;
set<int>s;

int main()
{
    int n;
    string st,str;
    cin >> st;
    for(int i  = 0; i < st.size(); i++)
    {
        if(st[i] >= '0' && st[i] <= '9')
        {
            str += st[i];
            //cout<<str<<endl;
            if(i == st.size() - 1)
            {
                stringstream dgt(str);
                int x = 0;
                dgt >> x;
                s.insert(x);
                str = ' ';
            }
        }
        else
        {
            stringstream dgt(str);
            int x = 0;
            dgt >> x;
            s.insert(x);
            str = ' ';
        }
    }
    set<int>::iterator it;
    int f=1;
    int cnt=0;
    for(it = s.begin(); it!= s.end(); )
    {
        //cout<<"------------"<<*it<<endl;
        int first = *it;
        it++;
        int last = *it;
        if(last - first == 1)
        {
            cnt++;
        }
        else
        {
//            cout<<cnt<<endl;
            //         cout<<first<<" "<<last<<endl;
            if(cnt > 0)
            {
                cout<<first-cnt<< "-"<<first;
            }
            else
            {
                cout<<first;
            }
            if(it != s.end())cout<<",";
            cnt = 0;
        }
    }
    return 0;
}
