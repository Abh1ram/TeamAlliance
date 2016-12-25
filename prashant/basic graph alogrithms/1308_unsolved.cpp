#include <stdio.h>
#include <iostream>

#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
	int s,t;
	int case_count = 1;
	int is_tree = 0;
	scanf("%d%d",&s,&t);

	while(s >=0 && t >= 0){
		if(s == 0 && t == 0){
			is_tree = 1;
		}

		else if(s != 0 && t != 0){
			int edge_count = 0;
			set <int> vertex;
			set <int> root;
			int temp_s,temp_t;
			int flag = 0
			temp_s = s;
			temp_t = t;
			int v_root = 0;

			vector <int> adj_list[1000000];
			int root[1000000];

			for(int i=0;i<1000000;i++){
				root[i] = -1;
			}

			adj_list[temp_s].push_back(temp_t);
			edge_count++;
			vertex.insert(temp_s);
			vertex.insert(temp_t);

			root.insert(temp_s);
			root.erase(temp_t);

			while(flag == 0 ){
				scanf("%d%d",&temp_s,&temp_t);
				if(temp_s != 0 && temp_t != 0){
					adj_list[temp_s].push_back(temp_t);
					edge_count++;

					vertex.insert(temp_s);
					vertex.insert(temp_t);

					root.insert(temp_s);
					root.erase(temp_t);
				}
				else{
					flag = 1;
				}
			}

			if(vertex.size() != edge_count + 1){
				is_tree = 0;
			}
			else {

				if(root.size != 1){
					is_tree = 0;
				}
				else{
					v_root = *(root.begin());
				}

				//bfs from v_root
				

			}


		}

		scanf("%d%d",&s,&t);
		case_count++;
		is_tree = 0;
	}
}