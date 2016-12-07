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

bool n_prime[1000001];

int main()
{
	int i,j,k;
	std::vector<int> v_primes;
	loop(i,2,1001)
	{
		if(n_prime[i] == 0)
		{
			if(i!=2)
				v_primes.pb(i);

			for(j=i*i; j<1000001; j+=i)
				n_prime[j] = 1;
		}
	}

	loop(i,1001,1000001)
	{
		if(n_prime[i] == 0)
			v_primes.pb(i);
	}

	int n;
	cin >> n;
	while(n)
	{

		for(std::vector<int>::iterator it = v_primes.begin(); it != v_primes.end(); it++)
		{
			if( n_prime[n- *it] == 0 )
			{
				printf("%d = %d + %d\n", n, *it, n-*it);
				break;
			}
		}
		cin >> n;
	}

	return 0;
}
