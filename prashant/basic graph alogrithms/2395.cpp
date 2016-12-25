#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;

struct edge{
	int src;
	int dest;
	int wt;
};


// vector <struct edge> E;
// vector <int> parent;
// vector <int> ht;

struct edge E[10000];
int parent[2000];
int ht[2000];

// vector < vector<struct edge>> graph;

bool mycomp(struct edge u,struct edge v){
	return u.wt < v.wt;
}

int find_par(int a){
	int par = -1;
	if(parent[a] != a){
		par =  find_par(parent[a]);
		parent[a] = par;
		return par;
	}
	else{
		return a;
	}
}

int main(){
	int n,m;

	cin >> n >> m;

	// parent.resize(n);
	// ht.resize(n);

	for(int i=0;i<m;i++){
		struct edge temp;
		int src,dest,wt;
		cin >> src >> dest >> wt;
		
		// temp.src = src;
		// temp.dest = dest;
		// temp.wt = wt;

		// E.push_back(temp);
		E[i].src = src;
		E[i].dest = dest;
		E[i].wt = wt;
	}

	for(int i=0;i<n;i++){
		parent[i] = i;
		ht[i] = 0;
	}

	// sort(E.begin(),E.end(),mycomp);
	sort(E,E+m,mycomp);

	int max_wt = 0;

	for(int i=0;i<m;i++){
		int a,b;
		a = E[i].src;
		b = E[i].dest;

		int p_a,p_b;

		p_a = find_par(a);
		p_b = find_par(b);

		if(p_a != p_b){
			if(ht[p_a] >= ht[p_b]){
				parent[p_b] = p_a;

				if(ht[p_a] == ht[p_b]){
					ht[p_a]++;
				}
			}
			else if(ht[p_b]> ht[p_a]){
				parent[p_a] = p_b;
			}

			if(E[i].wt > max_wt)
				max_wt = E[i].wt;

			
		}
	}

	printf("%d\n",max_wt);

	return 0;

}