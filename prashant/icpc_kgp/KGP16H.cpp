#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector <int> coal;
		coal.resize(n);
		for(int i=0;i<n;i++){
			int temp;
			cin >> temp;
			coal[i] = temp;
		}

		vector <int> tax;
		tax.resize(n-1);
		for(int i=0;i<n-1;i++){
			int temp;
			cin >> temp;
			tax[i] = temp;
		}

		vector <int> p;
		p.resize(n-1);
		for(int i=0;i<n-1;i++){
			int temp;
			cin >> temp;
			p[i] = temp;
		}

		int ans = coal[0];

		for(int i=0;i<n;i++){
			int p_temp=0;
			p_temp += coal[0];
			for(int j=1;j<=i;j++){
				p_temp +=coal[j];
				p_temp -=tax[j-1];
				if(p[j] == 2){
					p_temp -=tax[j-1];
				}
			}
			if(p_temp > ans){
				ans = p_temp;
			}
		}

		printf("%d\n",ans);
	}

	return 0;
}