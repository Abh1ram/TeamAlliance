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

int cat[101][200];
int length[101];

int add(int a[], int a_l, int b[], int b_l)
{
	int i, carry =0, len = MAX(a_l, b_l);
	int c[200] = {};
	lp(i,len)
	{
		c[i] = (a[i] + b[i] + carry)%10;
		carry = (a[i] + b[i] + carry)/10;
	}
	if(carry)
		len++;
	c[i] = carry;

	lp(i,len)
		a[i] = c[i];

	return len;

}

int mult(int a[], int a_l, int b[], int b_l, int c[])
{
	int i, j,z, carry=0, c2=0;
	lp(i, a_l)
	{
		carry = 0;
		c2=0;
		lp(j, b_l)
		{
			z = (a[i]*b[j])+carry;
		
			int y=z%10;
			int temp = c[i+j];

			c[i+j]= (temp+y+c2)%10;
			c2 = (temp+y+c2)/10;
			carry = z/10;
		}
		if(carry+c2)
		{
			c[i+j]+=carry+c2;
		}
	}
	int len = a_l+b_l-1;
	if(carry+c2)
		len++;
	return len;
}
void init_cat()
{
	cat[0][0]= cat[1][0] = length[0] = length[1] = 1;

	int i,j;
	loop(i,2,101)
	{
		int cat_len = 1;
		
		loop(j,0,i)
		{
			int ar[200] = {};
			int ar_len = mult(cat[j], length[j], cat[i-j-1], length[i-j-1], ar);
			cat_len = add(cat[i],cat_len, ar,ar_len);
		}
		
		length[i] = cat_len;
	}
}
int main()
{
	init_cat();
	
	int x, i;
	while(1)
	{
		cin >> x;
		if(x == -1)
			break;

		string ans ="";
		for(i=length[x]-1; i>=0;i--)
			ans+= (char)(cat[x][i]+'0');

		cout <<ans;
	}	
	return 0;
}
