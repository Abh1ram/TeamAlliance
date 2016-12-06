#include <stdio.h>

int main(){
	float sum = 0;
	float inp;
	for(int i=0;i<12;i++){
		scanf("%f",&inp);
		sum+=inp;
	}
	sum = sum / 12;
	// if(sum > (int)sum + 0.005){
	// 	sum = sum +0.005; 
	// }

	printf("$%.2f\n",sum);

	return 0;
}