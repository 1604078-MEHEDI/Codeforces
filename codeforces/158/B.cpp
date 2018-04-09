#include<bits/stdc++.h>
using namespace std;
//int ar[100001],br[100001],cr[100001],dr[100001];

int main()
{
    int n,t_two = 0,one=0,two=0,four=0,three=0,extra_two=0,x2=0,extra_one=0,total=0;
    scanf("%d",&n);
    int ar[n];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &ar[i]);

        if(ar[i]==4)four++;
        else if(ar[i]==3)three++;
            else if(ar[i]==2)two++;
            else if(ar[i]==1)one++;
    }

    extra_one = one - three;
    int add_two = two/2;
    t_two = two*2;

    if(t_two%4 !=0)
    {
        extra_two = t_two - add_two*4;
        x2 = (extra_two/4) + 1;
    }

    if(extra_one<=0)
    {
        int total = four + three + add_two + x2;

        printf("%d", total);
    }
    else
    {
        int extra = extra_one + extra_two;
       //  cout<<extra<<endl;

        if(extra%4==0)
        {
            total = four + three + add_two +(extra/4);
            //cout<<total<<endl;
        }
        else
        {
            total = four + three + add_two +((extra/4)+1);
        }

        printf("%d", total);
    }

}
