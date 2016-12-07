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
#define tup3 pair <tup2,int>
#define MAX(a,b) ((a)>=(b)?a:b)
#define MIN(a,b) ((a)<=(b)?a:b)
#define X first
#define Y second
#define pb push_back
#define pob pop_back

#define PI 3.14159265

int main()
{
	int t;
	cin >> t;
	while(t)
	{
		
		double r_b, r_s, temp1, temp2;
		int n;
		cin >> r_b >> n;
		temp1 = 1/sin(PI/n) ;
		r_s = r_b/(temp1+1);
		printf("Scenario #%d:\n%.3lf",t,r_s);
		t--;
	}
}
