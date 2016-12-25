#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <queue>
#include <utility>


using namespace std;

vector <vector < pair <int,int> > > graph;
 
class mycomp{
	public:
		bool operator()(pair <int, int> &a, pair <int,int> &b){
			return a.second > b.second;
		}
};

int main(){
	int n;

	cin >> n;

	while(n>0){
		graph.clear();
		graph.resize(n+1);

		for(int i=1;i<=n;i++){

			int m;
			cin >> m;

			for(int j=0;j<m;j++){
				int dest,wt;
				cin >> dest >> wt;
				pair <int,int> e;
				e = make_pair(dest,wt);
				graph[i].push_back(e);
			}
		}

		// for(int i=1;i<=n;i++){
		// 	for(int j=0;j<graph[i].size();j++){
		// 		printf("%d,%d ",graph[i][j].first,graph[i][j].second);
		// 	}
		// 	printf("\n");
		// }

		int start = 0;
		int ans = 1000000000;

		for(int i=1;i<=n;i++){
			if(graph[i].size() == 0){
				continue;
			}
			priority_queue < pair <int,int>,vector < pair <int,int> >,mycomp > q;
			
			// int dist[n+1];
			vector <int> dist;
			dist.resize(n+1);

			for(int j=1;j<=n;j++){
				dist[j] = -1;
			}

			dist[i] = 0;

			int dist_max = 0;
			
			// printf("########\n");
			for(int j=0;j<graph[i].size();j++){
				q.push(make_pair(graph[i][j].first,graph[i][j].second + dist[i]));
				// printf("%d,%d ",graph[i][j].first,graph[i][j].second + dist[i]);
			} 
			// printf("\n########\n");

			while(q.size() > 0){
				pair <int,int> cur = q.top();
				q.pop();
				// printf("%d,%d\n",cur.first,cur.second);

				if(dist[cur.first] == -1){
					dist[cur.first] = cur.second;

					if(cur.second > dist_max)
						dist_max = cur.second; 

					for(int j=0;j<graph[cur.first].size();j++){
						if(dist[graph[cur.first][j].first] == -1)
							q.push(make_pair(graph[cur.first][j].first,graph[cur.first][j].second + dist[cur.first]));
					}
				}
			}

			for(int k=1;k<=n;k++){
				if(dist[k] == -1){
					dist_max = 1000000000;
				}
			}

			if(dist_max < ans){
				start = i;
				ans = dist_max;
			}

			// for(int k=1;k<=n;k++){
			// 	printf("%d ",dist[k]);
			// }
			// printf("$$$\n");


		}

		if(ans == 1000000000){
			printf("disjoint\n");
		}
		else
			printf("%d %d\n",start,ans);


		cin >> n;
	}

	return 0;
}