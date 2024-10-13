#include <stdio.h>

// Author : Girish Kumar
// Date of Project Start : 8/10/2024

void empty_stdin(void){

	int c = getchar();

	while( c != '\n' && c != EOF){
		c = getchar();
	}

}
// clears the tictactoe board with spot numbering
void clear(char (*arr)[3]){
	char n='1';
	for(int i=0;i<3; i++){
		for(int j=0;j<3; j++){
							
			arr[i][j] = n;
			(int)n++;
		}

	}
	
}

// Prints the tictactoe graphic
void print(char (*arr)[3]){
	int count=0;
	for(int i=0; i<3; i++){

		printf(" %c | %c | %c",arr[i][0],arr[i][1],arr[i][2]);
		count++;
		printf("\n");
		(count <3)? printf("--- --- ---\n") :printf("\n\n");
	}

}


//Checks if the input move is valid 
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

	}else{}


}

//Enters the move in the Tic Tac Toe Board
int input(char (*arr)[3],char move){
	int location;char validchar;
	print(arr);
	printf("Enter Location :");
	int rtn ; //variable to save scanf return
	rtn = scanf("%d",&location);

	for(;;){
		
		if(rtn == EOF) {
			fputs("(User cancelled input.)\n",stderr);
			return 1;
		}else if(rtn == 0){
			fputs("(Invalid user input.)\n",stderr);
			empty_stdin();
			break;
		}else if( location<1 || location >9){
			fputs("(Invalid location range is [1-9].)\n",stderr);
			empty_stdin();
			break;
		}else{
			empty_stdin();
			break;
		}


	}
	if(rtn == 0 || location <1 || location > 9 || rtn == EOF){
		return 0;
	}
	if (location<=3){
		int local = location -1;
		if(validMove(arr,location)){
			
			validchar = move;
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
			validchar = move;
			
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

			validchar = move;
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
		return 0;
	}

	printf("Move Successful\n\n\n");
	
	return 1;
}



int logic(char (*arr)[3],char player){
	
	//Horizontal Logic

	for(int i=0; i<3;i++){

			if( arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
				printf("Congrats %c Won!\n\n",player);
				return 1;
			}
	}
	
	//Vertical Logic

	for(int j=0 ; j<3 ;j++){

		if( arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j]){
			printf("Congrats %c Won!\n\n",player);
			return 1;
		}
	}

	//Diagonal Logic

	if( arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
		printf("Congrats %c Won!\n\n",player);
		return 1;
	}else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]){
		printf("Congrats %c Won!\n\n",player);
		return 1;
	}else{

	}


	return 0;
}

int inputCheck(char** userinput){
//	printf("***%c***", **userinput);
	if(**userinput == 'X'|| **userinput == 'O') return 0;

	if (**userinput == EOF){
		printf("EOF error.");
		return 0;
	}
	else if( (**userinput != 'X') || (**userinput != 'O')){
		printf("Invalid Input : It must be X or O\n"); // This part is needed to be evaluated I have doubts.
		return 1;
	}else{
		printf("successful.");
		return 0;
	}

	return 0;

}
char startNewGame(char (*arr)[3] , char *player0){
	int checker = 0;
	clear(arr);
	printf("Enter Player 0 Sign : [ X or O]");
	
	scanf(" %c",player0);
	empty_stdin();
	while ( inputCheck(&player0) )
	{
		printf("Enter Player 0 Sign : [ X or O]");
		scanf(" %c",player0);
		empty_stdin();

	} 


	return *player0;
	

}


int main(){
	int count = 0;
	char player0,player1,ch = 'Y';
	char tic[3][3];
	clear(tic);
	int check,flag = 1;

	while(flag == 1){
	//	printf("*******%c*******",ch);
		if (ch == 'Y'){

			count = 0;
			check = startNewGame(tic,&player0);
		}else if (ch == 'N'){
		//	flag = 0;
			break;
		}else{
			printf("Wrong choice! Try again");
		}
	
	
		printf("Player 0 picked sign : %c\n",player0);


		if(player0 == 'X'){
			player1 = 'O';
			printf("Player 1 picked sign : %c\n",player1);
		}else{
			player1 = 'X';
			printf("Player 1 picked sign : %c\n",player1);
		
		}



		while(count < 9){

			if(count & 1){ 
				printf("\nThis Player 0 [%c]  Chance \n\n",player0);
				if(input(tic,player0)){
					count++;
				}
			}else{
				printf("\nThis Player 1 [%c] Chance \n\n",player1);
				if(input(tic,player1)){
					count++;
				}
			}

			if(count &1){
				if(logic(tic,player1)){
					printf("Do you want to play again? { Y/N }");
					scanf(" %c",&ch);
					break;
				}
			}else{
				if(logic(tic,player0)){
					printf("Do you want to play again? { Y/N }");
					scanf(" %c",&ch);
					break;
				}
			}	

		
			

			if(count == 9){
				print(tic);
				printf("\n\n\t\t*****Game Tied******\n\n\n");
				printf("Do you want to play again? { Y/N }");
				scanf(" %c",&ch);
				break;
				
			}


		}
		print(tic);
	}
	

	return 0;

}

