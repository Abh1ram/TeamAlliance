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


int main()
{
	int n, n_inv;
	while(1)
	{
		cin >> n >> n_inv;
		if(n == -1)
			break;

		std::vector<int> v;
		int i, j;
		loop(i,1,n+1)
		{
			int z = ((n - i)*(n - i - 1))/2;
			if(z >= n_inv)
				v.pb(i);
			else
				break;
		}
		if(i!=n+1)
		{
			int k = n - i + 1;
			int left = n_inv - z;
			v.pb(i+left);

			for(j = n;j>=i;j--)
				if(j!=(i + left))
					v.pb(j);
		}

		lp(i,n-1)
		printf("%d ",v[i]);
		printf("%d\n",v[n-1]);
	}
	return 0;
}
