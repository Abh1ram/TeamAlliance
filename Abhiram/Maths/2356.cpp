#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <utility>
#include <math.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#define loop(i,a,b) for(i=a;i<b;i++)
#define lp(i,n) for(i=0;i<n;i++)
#define lli long long int
#define us unsigned
#define tup2 pair <int,int>
#define dtup2 pair <double, double>
#define tup3 pair <tup2,int>
#define MAX(a,b) ((a)>=(b)?a:b)
#define MIN(a,b) ((a)<=(b)?a:b)
#define X first
#define Y second
#define pb push_back
#define pob pop_back
#define dist(a,b) sqrt((b.X - a.X)*(b.X - a.X) +(b.Y - a.Y)*(b.Y - a.Y))


int sums[10001];

int main()
{
	int n, i, j, ans, sum = 0;
	scanf("%d",&n);
	bool flag = 0;
	int inp[10001];
	loop(i,1,n+1)
	{
		scanf("%d",&inp[i]);
		sum = (sum + inp[i])%n;
		if(sums[sum] == 0)
			sums[sum] = i;
		else if(!flag)
		{
			flag = 1;
			//cout << i - sums[sum] << endl;
			printf("%d\n",i - sums[sum]);
			loop(j,sums[sum]+1, i+1)
				printf("%d\n",inp[j]);
				//cout << inp[j] << endl;
			
		}

	}

	if(!flag)
	{
		if(sums[0] != 0)
		{
			//cout << sums[0] << endl;
			printf("%d\n",sums[0]);
			loop(i,1,sums[0]+1)
				printf("%d\n",inp[j]);
		}
		else
			cout << 0<<endl;
	}

}
