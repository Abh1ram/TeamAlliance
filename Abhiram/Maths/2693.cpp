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


int check(vector<dtup2>& v, dtup2 c, int n)
{
	int i, count =0;
	lp(i,n)
	{
		if(dist(c, v[i]) <= 2.50001)
			count++;
	}

	return count;
}
int main()
{
	double x,y;
	std::vector<dtup2> v;
	int n = 0, j,i;
	while(cin >> x >> y)
	{
		n++;
		v.pb(make_pair(x, y));
	}

	int ans = 0;
	lp(i,n)
	{
		loop(j,i+1,n)
		{
			dtup2 mid;
			mid.X = (v[i].X + v[j].X)/2;
			mid.Y = (v[i].Y + v[j].Y)/2;

			double d = dist(v[i], v[j])/2;
			//cout << d<<endl;
			if(d<=2.5)
			{
			double r = 2.5;
			//cout << sqrt(r*r - d*d) << endl;
			
			double x1 = v[i].X - v[j].X;
			double y1 = v[i].Y - v[j].Y;
			double roo = sqrt(x1*x1 + y1*y1);
			dtup2 c1,c2;
			c1.X = mid.X + (-y1)*sqrt(r*r - d*d)/roo;
			c2.X = mid.X + (y1)*sqrt(r*r - d*d)/roo;	
			c1.Y = mid.Y + (x1)*sqrt(r*r - d*d)/roo;
			c2.Y = mid.Y + (-x1)*sqrt(r*r - d*d)/roo;
			//cout << dist(c1, v[i]) << " " << dist(c1,v[j]) << endl;
			//if(c1.X <=50.001 && c1.X >= -0.001 && c1.Y <=50.001 && c1.Y >= -0.001 )
				ans = MAX(ans, check(v,c1,n));
			//if(c2.X <=50.001 && c2.X >= -0.001 && c2.Y <=50.001 && c2.Y >= -0.001 )
				ans = MAX(ans, check(v,c2,n));
			}
			
		}
	}

	cout << ans;
	return 0;
}
