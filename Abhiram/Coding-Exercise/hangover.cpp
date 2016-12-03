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

int main()
{
	std::vector<double> v;
    int i;
    v.pb(0.0);
    loop(i,1,501)
    {
        v.pb(v[i-1]+1.0/(i+1.0));
        cout << v[i] << " ";
    }

    double inp=1.0;
    while(1)
    {
        cin >> inp;
        if(inp == 0)
            break;

        int l=0, h=500, mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(v[mid-1] >= inp )
                h=mid-1;
            else if(v[mid] < inp)
                l=mid+1;
            else
                break;
        }
        cout << mid << " card(s)" << endl;
    }
	return 0;
}
