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


int inv(string x)
{
    std::map<char, int> ex={{'A',0},{'C',1}, {'T',3}, {'G',2}};
    int ar[4]={};
    int count=0,i,j;
    lp(i,x.size())
    {
        auto search = ex.find(x[i]);
        ar[search->Y]++;
        loop(j,search->Y+1,4)
            count+=ar[j];
    }
    return count;
}

int main()
{
    int i,n,m;
    cin >> n >> m;
    std::vector<string> v;
    std::vector<tup2> v2;

    lp(i,m)
    {
        string x;
        cin >> x;
        v.pb(x);
        int z = inv(x);
        cout << z << x << endl
        v2.pb(make_pair(z,i));

    }

    sort(v2.begin(), v2.end());

    lp(i,m)
    {
        cout << v[v2[i].Y] << endl;
    }

    return 0;
}
