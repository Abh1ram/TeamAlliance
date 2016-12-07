#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <utility>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

#define loop(i,a,b) for(i=a;i<b;i++)
#define lp(i,n) for(i=0;i<n;i++)
#define lli long long int
#define us unsigned
#define tup2 pair <int,int>
#define tup3 pair <tup2,int>
#define MAX(a,b) ((a)>=(b)?a:b)
#define MIN(a,b) ((a)<=(b)?a:b)
#define X first
#define Y second
#define pb push_back
#define pob pop_back

#define modu 1

int nck[n + 1][n + 1];

void init_nck()
{
	int i, j;
	lp(i,n+1)
	{
		lp(j, i+1)
		{
			if(j == 0)
				nck[i][j] = 1;

			//else if(j>i)
			//	nck[i][j] = 0;
			else
				nck[i][j] = (nck[i-1][j] + nck[i-1][j-1]) % modu;
		}
	}
}
