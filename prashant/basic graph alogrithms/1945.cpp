#include <cstdio>
#include <iostream>

#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <queue>

#include <set>

using namespace std;

queue < vector <int> > q;
set <vector <int> > s;

void add_node(int a,int b,int c){
	vector <int> temp,temp1;

	temp.push_back(a);
	temp.push_back(b);

	temp1.push_back(b);
	temp1.push_back(a);

	if((s.insert(temp)).second && s.insert(temp1).second){
		temp.push_back(c);
		q.push(temp);
	}
}


int main(){
	int n;

	cin >> n;

	// queue <pair <int,int> > q;

	add_node(1,0,0);

	int flag = 0;

	int count = 0;
	int ans = -1;

	while(!flag){
		
		vector <int> cur = q.front();
		q.pop();
		//printf("%d %d\n",cur.first,cur.second);

		int a = cur[0];
		int b = cur[1];
		int ht = cur[2];


		if(a == n || b == n){
		 	ans = ht;
			break;
		}
		else{

			if(a > n && b > n){
				;
			}
			else{
				add_node(a,a+b,ht+1);
				add_node(a+a,b,ht+1);
				add_node(a,a+a,ht+1);
				add_node(a,b+b,ht+1);
				add_node(a+b,b,ht+1);
				add_node(b+b,b,ht+1);

			}

			if(a>b){
				add_node(a-b,b,ht+1);
				add_node(a,a-b,ht+1);
			}
			else{
				add_node(a,b-a,ht+1);
				add_node(b-a,b,ht+1);
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}