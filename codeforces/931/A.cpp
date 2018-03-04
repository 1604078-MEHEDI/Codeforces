#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,result,i=0,j=0;
    cin>>a>>b;
    if(a>b)
    {
        for(int k=1; ; k++)
        {
            if(a==b)break;
            a--;
            i++;
            if(a==b)break;
            b++;
            j++;
            if(a==b)break;
        }
        result = i*(i+1)/2 + j*(j+1)/2;
        cout<<result;
    }
    else
    {
        for(int k=1; ; k++)
        {
            if(a==b)break;
            a++;
            i++;
            if(a==b)break;
            b--;
            j++;
            if(a==b)break;
        }
        result = i*(i+1)/2 + j*(j+1)/2;
        cout<<result;
    }
}
