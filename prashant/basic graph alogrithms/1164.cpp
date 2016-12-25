#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int dfs(int *,int);

vector < vector <int> > graph;

int main(){
	int row,column;
	cin >> row >> column;

	graph.resize(row*column);

	for(int i=0;i<row;i++){
		for(int j=0;j<column;j++){

			int temp;
			cin >> temp;
			int d;

			//west
			d = temp % 2;
			if(d == 0){
				graph[i*column + j].push_back(i*column + j-1);
			}
			temp /=2;

			//north
			d = temp % 2;
			if(d == 0){
				graph[i*column + j].push_back((i-1)*column + j);
			}
			temp /=2;
			
			//east
			d = temp % 2;
			if(d == 0){
				graph[i*column + j].push_back(i*column + j+1);
			}
			temp /=2;

			//south
			d = temp % 2;
			if(d == 0){
				graph[i*column + j].push_back((i+1)*column + j);
			}
		}
	}

	// int reached[row*column];
	int *reached =(int *) malloc(row*column*sizeof(int));
	for(int i=0;i<row*column;i++){
		reached[i] = 0;
	}

	int flag = 1;
	int root = 0;
	reached[0] = 1;		
	int count = 0;
	int area = 0;
	while(flag){
		int temp_area = dfs(reached,root);

		if(temp_area > area){
			area = temp_area;
		}

		count++;
		flag = 0;
		for(int i=0;i<row*column;i++){
			if(reached[i] == 0){
				flag = 1;
				root = i;
				reached[root] = 1;
				break;
			}
		}
	}

	printf("%d\n%d\n",count,area);

	return 0;
}

//returns area (no of vertices in scc)
int dfs(int *reached,int vertex){
	int count = 1;

	for(int i=0;i< graph[vertex].size();i++){
		if(reached[(graph[vertex][i])] == 0){
			reached[(graph[vertex][i])] = 1;
			count+=dfs(reached,graph[vertex][i]);
			
		}
	}

	return count;
}