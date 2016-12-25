#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node{
	struct node * children[26];
	bool isLeaf;
	int num_children;
};

struct ret{
	int ans;
	int spare;
};

struct node *get_node(void){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->isLeaf = 0;
	temp->num_children = 0;

	for(int i=0;i<26;i++){
		temp->children[i] = NULL;
	}

	return temp;
}

void insert(struct node *root,string str){
	int level = 0;
	int len = str.size();
	int idx = 0;
	struct node *cur = root;

	for(level = 0;level<len;level++){
		idx = str[level] - 'a';
		if(cur->children[idx] == NULL){
			cur->children[idx] = get_node();
		}
		cur->num_children++;
		cur = cur->children[idx];

	}

	cur->isLeaf = 1;
}

struct ret search(struct node *root,string str,int cur_level){
	int idx;
	struct node *cur = root;

	int extra = 0;

	if(cur == NULL){
		struct ret temp;
		temp.ans = 0;
		temp.spare = 0;
		return temp;
	}


	if(cur_level == str.size()){
		if(cur->isLeaf == 1){
			extra = 1;
		}

		struct ret temp;
		temp.ans = 1;
		temp.spare = cur->num_children - 1 + extra;

		return temp;
	}

	idx = str[cur_level] - 'a';
	
	if(cur->children[idx] == NULL){
		if(cur->isLeaf == 1){
			extra = 1;
		}

		struct ret temp;
		temp.ans = 1;
		temp.spare = cur->num_children - 1 + extra;

		return temp;
	}
	else{
		struct ret r = search(cur->children[idx],str,cur_level+1);
		
		if(cur->isLeaf == 1){
			extra = 1;
		}

		if(cur->num_children + extra > r.ans + r.spare){
			struct ret temp;
			temp.ans = r.ans + 1;
			temp.spare = extra + r.spare + cur->num_children - (r.ans + r.spare) - 1;
			return temp;
		}
		else{
			struct ret temp;
			if(r.spare > 0){
				temp.ans = r.ans + 1;
				temp.spare = r.spare - 1;
			}
			else{
				temp.ans = r.ans;
				temp.spare = r.spare;
			}

			return temp;
		}


	}


}

int main(){
	int n,m;
	cin >> n >> m;

	vector <string> vocab_a,vocab_b;
	vocab_a.resize(n);
	vocab_b.resize(m);
	
	for(int i=0;i<n;i++){
		cin >> vocab_a[i];
	}

	for(int i=0;i<m;i++){
		cin >> vocab_b[i];
	}

	//create a trie for vocab_b;

	struct node *root = get_node();

	for(int i=0;i<m;i++){
		insert(root,vocab_b[i]);
	}

	int ans = 0;

	for(int i=0;i<n;i++){
		int idx = (vocab_a[i])[0] - 'a';
		struct ret max = search(root->children[idx],vocab_a[i],1);
		// cout << vocab_a[i] << max;
		// printf("\n");
		ans += max.ans;
	}

	printf("%d\n",ans);

	return 0;
}