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

us int maxi(us int n)
{
	int i = 0;
	us int x = n;
	while(x%2 == 0)
	{
		i++;
		x/=2;
	}

	x=1;
	while(i>0)
	{
		i--;
		n+=x;
		x*=2;
	}
	return n;
}

us int mini(us int n)
{
	int i = 1;
	us int x = n;
	while(x%2 == 0)
	{
		i++;
		x/=2;
	}
	us int x =1;
	while(i > 1)
	{
		x*=2;
		i--;
	}
	n = n- x +1;
	
	return n;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		us int n;
		cin >> n;
		cout << maxi(n) << " "<< mini(n)<< endl; 
	}
	return 0;
}
