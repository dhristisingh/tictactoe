#include <stdio.h>



int main(){


	int total, posi;

	scanf("%d %d",&total,&posi);

	int arr[total];

	for(int i = 0 ; i< total ; i++){

		scanf("%d",&arr[i]);
	
	}

	posi--;


	int target = arr[posi];
	int tmpposi = posi;

	if( target == 0){

		for(int k = tmpposi ; k>=0 ; k--){

			if( arr[k] == 0) posi--;
			else break;

		}

	}

	for( int j = tmpposi+1 ; j <total ; j++){

		if( arr[j] == target && arr[j] != 0) posi++;
		else break;
	}

	printf("%d",posi+1);
	


	return 0;



}
