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

lli area;
int x,y;
int dx[10] = {0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
int dy[10] = {0, -1, -1, -1, 0, 0, 0, 1, 1, 1};

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		x = y = 0; 
		area = 0;
		char c = getchar();
		if(c=='\n')
		c = getchar();
		
		//cout << (int)c<< endl;
		x+=dx[c-'0'];
		y+=dy[c-'0'];

		while((c=getchar())>=38)
		{
			//cout << (int)c << x << y << endl;
			int tx = x+dx[c-'0'];
			int ty = y+dy[c-'0'];

			area+=tx*y - ty*x;
			x = tx;
			y = ty;
		}
		if(area < 0)
			area = -(area);
		
		if(area%2 == 0)
			cout << area/2 << endl;

		else
			printf("%.1lf\n", area/(double)2.0);
		//t--;

	}
	return 0;
}
