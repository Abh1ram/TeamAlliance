#include <stdio.h>

int main(){
	
	float inp;
	scanf("%f",&inp);

	while(inp != 0.00){
		int i=2;
		int count = 1;
		inp -= 1.0/i;
		while(inp > 0){
			count++;
			i++;
			inp -= 1.0/i;
		}

		printf("%d card(s)\n",count);

		scanf("%f",&inp);		
	}

	return 0;
}