#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;

	cin >> t;

	while(t--){
		int n,k;

		cin >> n >> k;

		vector <int> ht;

		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			ht.push_back(temp);
		} 

		sort(ht.begin(),ht.end());

		int min_diff = 1000000000;
		for(int i=0;i<n-k+1;i++){
			if(ht[i+k-1] - ht[i] < min_diff){
				min_diff = ht[i+k-1] - ht[i];
			}
		}

		printf("%d\n",min_diff);
	}

	return 0;
}