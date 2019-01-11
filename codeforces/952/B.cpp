#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=0; i<10; i++)
    {
        string s;
        cout<<i<<endl;
        getline(cin,s);
        if(s=="cool" ||s=="not bad" ||s=="great" ||s=="don't think so" ||s=="don't touch me!")
        {
            cout<<"normal"<<endl;
            return 0;
        }
        else if(s=="terrible" ||s=="worse" ||s=="are you serious?" ||s=="go die in a hole" ||s=="don't even" ||s=="no way")
        {
            cout<<"grumpy"<<endl;
            return 0;
        }
    }

}