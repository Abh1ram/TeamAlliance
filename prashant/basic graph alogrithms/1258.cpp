#include <stdio.h>
#include <iostream>

#include <vector>
#include <set>

#include <algorithm>

struct edge{
	int s;
	int t;
	int wt;
};

edge E[1000000];
int parent[100];
int ht[100];

bool mycomp(struct edge i, struct edge j){
	return i.wt < j.wt;
}

int find(int a){
	if(parent[a] == a){
		return a;
	}
	else{
		return find(parent[a]);
	}
}


using namespace std;

int main(){
	int n;
	while(scanf("%d",&n) == 1){

		int idx = 0;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int temp;
				scanf("%d",&temp);
				if(i!=j){
					E[idx].s = i;
					E[idx].t = j;
					E[idx].wt = temp;
					idx++;
				}
			}
		}

		sort(E,E+idx,mycomp);



		for(int i=0;i<n;i++){
			parent[i] = i;
			ht[i] = 0;
		}

		int len = 0;

		for(int i = 0; i< idx;i++){
			int a,b;
			a = E[i].s;
			b = E[i].t;
			int p_a = find(a);
			int p_b = find(b);

			if(p_a == p_b){
				;
			}
			else{
				if(ht[p_a] > ht[p_b]){
					parent[p_b] = p_a;
				}
				else if(ht[p_a] == ht[p_b]){
					parent[p_b] = p_a;
					ht[p_a]++;
				}
				else{
					parent[p_a] = p_b;
				}

				len += E[i].wt; 
			}
		}

		printf("%d\n",len);
	}

	return 0;

}