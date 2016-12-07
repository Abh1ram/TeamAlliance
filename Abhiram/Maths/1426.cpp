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
	int n, i, j;
	us ans = 0;
	cin >> n;
	int orig[10001], v[10001];
	lp(i,n)
	{
		cin >> orig[i+1];
		v[i+1] = orig[i+1]%n;
		if(v[i+1] == 0)
			ans = orig[i+1];
	}

	if(ans)
		cout << 1 << endl << ans << endl;

	else
	{
		
	}

	while(1)
	{
		cin >> n;
		if(n == 0)
			break;

		int i, j, k;
		bool flag = 0;
		

		v.pb(0); // padding
		v.pb(1);
		loop(i,2,lim+1)
		{
			v.pb((v[i-1]*10)%n);
			if(v[i] == 0)
			{
				flag = 1;
				string x = "1";
				lp(j,i-1)
					x+=(char)(0+'0');
				cout << x << endl;
				break;
			}
		}

		if(!flag)
		{
			int max = n; // max possible sum

			bool dp[lim+1][200];

			lp(i,lim+1)
			{
				lp(j, max+1)
				{
					if(j==0)
						dp[i][j] = 1;

					else if(i==0)
						dp[i][j] = 0;
					else
					{
						dp[i][j] = dp[i-1][j] | dp[i-1][(j-v[i]+n)%n];

					}
				}	
			}

			k = n;

			string ans ="";
			bool ans_flag=0;
			for(j=lim; j>0; j--)
			{
				if(dp[j-1][k] == 0)
				{
					ans+='1';
					k = (k - v[j] +n)%n;
					ans_flag = 1;
					continue;
				}	
				if(ans_flag)
					ans+='0';
			}

			cout << ans << endl;


		}
	}
	return 0;
}
