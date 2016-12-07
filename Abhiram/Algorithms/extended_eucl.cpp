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

int gcd(int a, int b) // ordering of a and b is immaterial
{
	while(b)
	{
		int r = a%b;
		a=b;
		b=r;
	}
	return a;
}

/* returns pair (x,y) s.t a*x + b*y = gcd(a,b) */
tup2 ext_euc(int a, int b)  // a can be less than b
{
	int fa=1, fb=0, sa=0, sb=1, x, r;
	while(1)
	{
		x = a/b;
		r = a%b;
		if(r == 0)
			return (make_pair(sa, sb));

		int temp_a = fa;
		int temp_b = fb;
		fa = sa;
		fb = sb;
		sa = temp_a - x*sa;
		sb = temp_b - x*sb;
		a = b;
		b = r;
	}
}

/* Returns x(a inverse) s.t a*x % n == 1 */
int multiplicative_inv(int a, int n)
{
	if(gcd(a,n) != 1)
		return -1;
	else
	{
		tup2 ans = ext_euc(a,b);
		return (((ans.X) % n) + n)%n;
	}
}

// int main()
// {
// 	cout << multiplicative_inv(5,7);
// }

/* Returns x s.t x%m==a and x%n ==b and
x < n*m  */
int chinese_remainder(int a, int b, int m, int n)
{
	if(gcd(m, n) != 1)
		return -1;

	return (a*n*multiplicative_inv(n,m) + b*m*multiplicative_inv(m,n)) % (n*m);
}
