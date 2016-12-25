#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;

bool myComp(pair < int, int > i, pair < int, int > j){
 	return i.first < j.first;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);

	// char inp[m][n+1];
	vector <string> inp;

	for(int i=0;i<m;i++){
		string temp;
		cin >> temp;
		inp.push_back(temp);
	}

	vector< pair < int, int > > count;

	// int count[m][2];
	for(int i=0;i<m;i++){
		pair < int,int > elem = make_pair(0,i);
		// count[i][0] = 0;
		// count[i][1] = i;
		count.push_back(elem);
	}

	for(int i=0;i<m;i++){
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(inp[i][j] > inp[i][k]){
					count[i].first++;
				}
			}
		}
	}

	stable_sort(count.begin(),count.end(),myComp);

	for(int i=0;i<m;i++){
		cout << inp[count[i].second] <<"\n" ;

	}

	return 0;

}