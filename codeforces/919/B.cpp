#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int k,p,count,result;

    while(cin>>k)
    {
        count=0;
        for(int i=19; ; i++)
        {
            result = i;
            int sum=0;
            while(result !=0)
            {
                p = result%10;
                sum += p;
                result /=10;
            }
            if(sum==10)
            {
                count++;
                if(count==k)
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}
