#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct e{
	int v1;
	int v2;
	bool marked;
};

int main(){
	int t;
	cin >> t;

	while(t--){
		int n,m;
		cin >> n >> m;

		vector <vector <pair <int,int> > > graph;
		graph.resize(n+1);

		vector < struct e > edge;
		edge.resize(m+1);

		int cnt = 0;
		for(int i=0;i<m;i++){
			int v1,v2;
			cin >> v1 >> v2;
			cnt++;
			graph[v1].push_back(make_pair(v2,cnt));
			graph[v2].push_back(make_pair(v1,cnt));

			edge[cnt].v1 = v1;
			edge[cnt].v2 = v2;
			edge[cnt].marked = 0;
		}

		vector <int> ans;

		for(int i=1;i<m+1;i++){
			if(edge[i].marked == 0){
				ans.push_back(edge[i].v1);
				ans.push_back(edge[i].v2);
				edge[i].marked = 1;

				int v1,v2;
				v1 = edge[i].v1;
				v2 = edge[i].v2;


				for(vector<pair <int,int> >::iterator it = graph[v1].begin();it != graph[v1].end();++it){
					if(edge[(*it).second].marked == 0){
						edge[(*it).second].marked = 1;
					}
				}

				for(vector<pair <int,int> >::iterator it = graph[v2].begin();it != graph[v2].end();++it){
					if(edge[(*it).second].marked == 0){
						edge[(*it).second].marked = 1;
					}
				}
			}
		}

		printf("%d\n",ans.size());
		for(vector<int>::iterator it = ans.begin();it!= ans.end();++it){
			printf("%d ",*it);
		}
		printf("\n");
	}

	return 0;
}