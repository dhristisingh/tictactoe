#include <stdio.h>

//comment
void clear(char (*arr)[3]){
	char n='1';
	for(int i=0;i<3; i++){
		for(int j=0;j<3; j++){
							
			arr[i][j] = n;
			(int)n++;
		}

	}
	
}

void print(char (*arr)[3]){
	int count=0;
	for(int i=0; i<3; i++){

		printf(" %c | %c | %c",arr[i][0],arr[i][1],arr[i][2]);
		count++;
		printf("\n");
		(count <3)? printf("--- --- ---\n") :printf("\n");
	}

}

int validMove(char (*arr)[3],int location){
	int local;
	if (location<=3){
		local = location -1;
		if (arr[0][local] == 'X' || arr[0][local] == 'x' || arr[0][local] == 'O' || arr[0][local] == 'o'){
			return 0;
		}else{
			return 1;
		}

	}else if(location<=6){
		local = location -4;
		if (arr[1][local] == 'X' || arr[1][local] == 'x' || arr[1][local] == 'O' || arr[1][local] == 'o'){
			return 0;
		}else{
			return 1;
		}

	}else if(location<=9){
		local = location -7;
		if (arr[2][local] == 'X' || arr[2][local] == 'x' || arr[2][local] == 'O' || arr[2][local] == 'o'){
			return 0;
		}else{
			return 1;
		}

	}else{
		printf("\nInvalid Location\n");
	}

}

int input(char (*arr)[3]){
	int location;char validchar;
	print(arr);
	printf("Enter Location :");
	scanf("%d",&location);

	if (location<=3){
		int local = location -1;
		if(validMove(arr,location)){
			
			printf("\nEnter Input :");
			scanf(" %c",&validchar);
			if(validchar == 'X' || validchar == 'x' || validchar == 'O' || validchar == 'o'){
				arr[0][local] = validchar;

			}else{
				printf("\nInvalid Move\n");
				return 0;
			}

		}else{
			printf("\nAlready Occupied\n");
			return 0;
		}
	}else if(location<=6){
		int local = location -4;
		if(validMove(arr,location)){
			printf("\nEnter Input :");
			scanf(" %c",&validchar);
			if(validchar == 'X' || validchar == 'x' || validchar == 'O' || validchar == 'o'){
				arr[1][local] = validchar;

			}else{
				printf("\nInvalid Move\n");
				return 0;
			}
				
		}else{
			printf("\nAlready Occupied\n");
			return 0;
		}
	}else if(location<=9){
		int local = location - 7;
		if(validMove(arr,location)){

			printf("\nEnter Input :");
			scanf(" %c",&validchar);
			if(validchar == 'X' || validchar == 'x' || validchar == 'O' || validchar == 'o'){
				arr[2][local] = validchar;

			}else{
				printf("\nInvalid Move\n");
				return 0;
			}


		}else{
			printf("\nAlready Occupied\n");
			return 0;
		}
	}else{
		printf("\nInvalid Location\n");
		return 0;
	}

	printf("Move Successful\n\n\n");
	
	return 1;
}





int main(){
	int count = 0;
	char tic[3][3];
	clear(tic);
	while(count < 9){

		
		if(input(tic)){
			count++;
		}

		printf("\n%d\n",count);

	}

	print(tic);
	

	return 0;

}

