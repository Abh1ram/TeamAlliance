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

int codes[2][10001];
int dest[2][10001];
int dir1[5]={0,+1,-1,-1,1};
int dir2[5]={0,+1,+1,-1,-1};
int main()
{
	int i, j, n;
	scanf("%d",&n);
	j=1;
	lp(i,2*n)
	{
		if(i%2)
		{
			scanf("%d",&codes[1][j]);
			j++;
		}
		else
			scanf("%d", &codes[0][j]);
	}
	int flips[2]={};

	int x;
	lp(i,n)
	{
		scanf("%d",&x);
		dest[0][i+1] = dir1[x];
		dest[1][i+1] = dir2[x];
		
		if(i>0)
		{
			lp(j,2)
				if(dest[j][i+1] != dest[j][i])
					flips[j]++;
		}

	}

	lp(j,2)
		sort(codes[j]+1, codes[j]+n+1);


	int first[2],second[2];
	char sign[2][2];
	lp(j,2)
	{
		first[j] = second[j] = n-flips[j];
		if(dest[j][1] == 1)
			sign[j][0] = sign[j][1] = '+';
		else
			sign[j][0] = sign[j][1] = '-';
	}

	printf("%c%d %c%d\n",sign[0][0],codes[0][first[0]],sign[1][0],codes[1][first[1]]);

	loop(i,2,n+1)
	{
		lp(j,2)
		{
			if(dest[j][i-1] == dest[j][i])
			{
				first[j]--;
				sign[j][0] = (sign[j][0]=='+')?'-':'+';
				printf("%c%d",sign[j][0],codes[j][first[j]]);
			}	
			else
			{
				second[j]++;
				sign[j][1] = (sign[j][1]=='+')?'-':'+';
				printf("%c%d",sign[j][1],codes[j][second[j]]);
			}
			if(j==0)
				printf(" ");
		}
		printf("\n");
	}


	return 0;
}
