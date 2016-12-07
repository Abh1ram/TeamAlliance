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

int main()
{
	dtup2 inp[3];
	int i,j;
	while(cin >> inp[0].X >> inp[0].Y)
	{
		lp(i,2)
			cin >> inp[i+1].X >> inp[i+1].Y;

		double a,b,c,d,e,f;
		dtup2 ans, temp[2];
		a = inp[0].X - inp[1].X;
		b = inp[0].Y - inp[1].Y;
		c = -a*(inp[0].X + inp[1].X)/2 -b*(inp[0].Y + inp[1].Y)/2;
		d = inp[2].X - inp[1].X;
		e = inp[2].Y - inp[1].Y;
		f = -d*(inp[2].X + inp[1].X)/2 -e*(inp[2].Y + inp[1].Y)/2;

		ans.X = (e*c - b*f) /(b*d -a*e);
		ans.Y = (a*f - c*d) /(b*d -a*e);
		double output = 2*3.141592653589793*sqrt((ans.X- inp[0].X)*(ans.X- inp[0].X) + (ans.Y- inp[0].Y)*(ans.Y- inp[0].Y));
		printf("%.2lf\n",output); 
	}
	return 0;
}
