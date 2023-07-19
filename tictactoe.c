#include<stdio.h>
#define Board_Size 3

char arr[Board_Size][Board_Size] = {{'1','2','3'},
									{'4','5','6'},
									{'7','8','9'}};						
void print_table();
void take_turn(int, int,char,char);
int check_win();



int main()
{
	int player = 1,choice = 0;
	char p1,p2;
	printf("player 1 Choose X or O your symbol: ");
	scanf(" %c",&p1);
	if (p1 == 'X')
	{
		p2 = 'O';
	}
	else
	{
		p2 = 'X';
	}
	printf("Player 1 is %c\n",p1);
	printf("Player 2 is %c\n",p2);
	printf("\n");
	print_table();
	printf("\n");
	take_turn(player,choice,p1,p2);
	
	
}
void print_table()
{
	int i,j;
	for(i = 0; i < Board_Size; i++)
	{
		for(j = 0; j < Board_Size; j++)
		{
			printf("%c\t", arr[i][j]);
		}
		printf("\n");
	}
}
void take_turn(int player,int choice, char p1, char p2)
{
	char turn;
	
	while(1)
	{
	player = ((player % 2))? 1:2;
	turn = (player == 1)? p1:p2;
	printf("player %d turn: ", player);
	scanf(" %d",&choice);
	printf("\n");
	if((choice==1) && (arr[0][0] == '1'))
	{
		arr[0][0] = turn;
	}
	else if((choice==2) && (arr[0][1] == '2'))
	{
		arr[0][1] = turn;
	}
	else if((choice==3) && (arr[0][2] == '3'))
	{
		arr[0][2] = turn;
	}
	else if((choice==4) && (arr[1][0] == '4'))
	{
		arr[1][0] = turn;
	}
	else if((choice==5) && (arr[1][1] == '5'))
	{
		arr[1][1] = turn;
	}
	else if((choice==6) && (arr[1][2] == '6'))
	{
		arr[1][2] = turn;
	}
	else if((choice==7) && (arr[2][0] == '7'))
	{
		arr[2][0] = turn;
	}
	else if((choice==8) && (arr[2][1] == '8'))
	{
		arr[2][1] = turn;
	}
	else if((choice==9) && (arr[2][2] == '9'))
	{
		arr[2][2] = turn;
	}
	else{
		printf("Invalid move\n");
		continue;
	}
	print_table();
	printf("\n");
	
	if(check_win())
	{
		printf("PLAYER (%c) IS WINNER!!\n", turn);
		break;
	}
	
	//printf("\n");
	
	player++;
	}
}
int check_win()
{
	int i, j;
	/*check for columns*/
	for (j = 0; j<Board_Size;j++)
	{
		if(arr[0][j] == arr[1][j] && arr[1][j] == arr[2][j])
		{
			return 1;
		}
	}
	/*check for rows*/
	for (i = 0; i<Board_Size;i++)
	{
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2])
		{
			return 1;
		}
	}
	/*check diagonal*/
	if(((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2])) ||((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0])))
	{
		return 1;
	}
	return 0;
}