#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,m,C;
		cin >> n >> m >> C;

		vector <int> c;
		c.resize(C+1);
		for(int i=1;i<=C;i++){
			cin >> c[i];
		}

		vector<vector<int> > arr;
		arr.resize(n);
		for(int i=0;i<n;i++){
			arr[i].resize(m);
		}

		// printf("done\n");

		bool dir=0; //0 = right, 1 = left
		int row=0,col=0;

		for(int i=1;i<=C;i++){
			while(c[i] > 0){
				if(dir == 0){
					arr[row][col] = i;
					col++;
					if(col > m-1){
						col--;
						dir = (dir+1)%2;
						row++;
					}
				}
				else{
					arr[row][col] = i;
					col--;
					if(col < 0){
						col++;
						dir = (dir+1)%2;
						row++;
					}
				}
				c[i]--;
			}

		}

		// printf("donw2\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}

	}

	return 0;
}