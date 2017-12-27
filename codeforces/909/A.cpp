#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,p=0;
    string s1,s2,s3,s4;
    cin>>s1>>s2;
    s3 = s1[0];
 //   cout<<s1[0];
    for(i=1; i<s1.length(); i++)
    {
        if(s1[i]<s2[0])
        {
            p = i;
            s3[i] = s1[i];
          //  cout<<s3[i];
        }
        else
            break;
    }
    for(i=0; i<=p; i++)
        cout<<s3[i];
    cout<<s2[0];
}
