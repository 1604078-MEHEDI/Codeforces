#include<bits/stdc++.h>
using namespace std;
#define inf 10000000001

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
   int n;
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
    {
		cin>>array[i];
	}
	//int count=0;
	while(1)
    {
		for(int i=0;i<n;i++)
		{
			if(array[i]<=i)
			{
				cout<<i+1;
				return 0;
			}
			array[i]=array[i]-n;
		}
	}
}
