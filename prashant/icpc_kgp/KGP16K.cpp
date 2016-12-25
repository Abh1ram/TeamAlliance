#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;

		vector <int> base;
		base.resize(n+1);
		for(int i=1;i<=n;i++){
			cin >> base[i];
		}

		vector <int> seq;
		seq.resize(m+1);
		for(int i=1;i<=m;i++){
			cin >> seq[i];
		}

		vector <int> pi;
		pi.resize(m+1);

		int k=0
	}
}