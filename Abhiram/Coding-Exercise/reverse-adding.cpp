#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <utility>
#include <math.h>
#include <map>
#include <vector>
#include <string>
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

int main()
{
   int n,i,j;
   cin >> n;

   lp(i,n)
   {
    string x,y, x2="", y2="";
    cin >> x>> y;

    //reverse(x.begin(),x.end());
    //reverse(y.begin(),y.end());
    //cout << x <<y;
    int el1=0,el2=0;
    for(j=x.size()-1;j>=0;j--)
        if(x[j]!='0')
            break;
    el1=j+1;

    for(j=y.size()-1;j>=0;j--)
        if(y[j]!='0')
            break;
    el2=j+1;
	//cout << el2 << endl;
    if(el2>el1)
    {
        x2=x;
        x=y;
        y=x2;
    }
	el1 = MAX(el1,el2);
    loop(j,y.size(),el1)
        y+='0';
	//cout << x << y << el1 <<  el2 << endl;
    string z="";
    int carry=0;
    loop(j,0,el1)
    {
        int a=x[j]-'0', b=y[j] - '0', c;
        c=(a+b+carry)%10;
        carry = (a + b+ carry)/10;
        z+= (char)(c+'0');
    }
    if(carry == 1)
        z+='1';

	string ans="";
	int flag=0;
	lp(j,z.size())
	{
		if(z[j]!='0')
		flag=1;
		if(flag)
		ans+=z[j];
	}
    cout << ans << endl;


   }
}
