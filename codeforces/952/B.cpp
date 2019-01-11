#include<bits/stdc++.h>
using namespace std;

int main()
{

    for(int i=0; i<10; i++)
    {
        string str;
        cout<<i<<endl;
         getline(cin, str);
        if(str=="cool" ||str=="not bad" ||str=="great" ||str=="don't think so" ||str=="don't touch me!")
        {
            cout<<"normal"<<endl;
            return 0;
        }

                else if(str =="terrible" ||str =="worse" ||str =="are you serious?" ||str =="go die in a hole" ||str =="don't even" ||str =="no way")
        {
             cout<<"grumpy"<<endl;
            return 0;
        }
    }
}
