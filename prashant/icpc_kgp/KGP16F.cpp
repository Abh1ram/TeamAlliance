#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int t;

	cin >>t;

	while(t--){
		int n,k;

		cin >> n >> k;

		vector<int> ar;
		ar.resize(n+1);

		for(int i=1;i<=n;i++){
			cin >> ar[i];
		}

		sort(ar.begin(),ar.end());

		vector <vector <int> > dp;

		dp.resize(n+1);
		for(int i=0;i<=n;i++){
			dp[i].resize(k+1);
		}

		for(int i=0;i<=n;i++){
			for(int j=0;j<=k;j++){
				if(j==1){
					dp[i][j] = 0;
					continue;
				}
				if()

			}
		}


		for(int i=0;i<=n-1;i++){
			for(int j=0;j<=k;j++){
				printf("%d ",dp[i][j]);
			}
			printf("\n");
		}

		printf("%d\n",ar[n] - ar[1] - dp[n-1][k]);

	}

	return 0;
}