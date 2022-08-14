#include "stdio.h"
#include "STD_TYPES.h"
#include "stdlib.h"
#include "time.h"
const u8 BOARDROWS = 10;
const u8 BOARDCOLOUMNS = 10;

void fill_Random (u8 arr[BOARDROWS][BOARDCOLOUMNS], u8 max);
void print(u8 arr[BOARDROWS][BOARDCOLOUMNS]);
u8 options();
void main(void)
{
	/*initializing the board */
	u8 arr[BOARDROWS][BOARDCOLOUMNS];

	fill_Random(arr, 2); /*getting the board preped for the first time*/
	print(arr);/*printing the board*/

	u8 choice=options(); /*to get wheather the user is driving a car (1) or walking (0)*/

	u8 departureRow,departureColoumn;/*To get the horizontal and vertical coordinates for departure */
	u8 destinationRow,destinationColoumn;/*To get the horizontal and vertical coordinates for destination*/

	input1: /*This input declares the the need for the departure location*/
	printf("please enter your current position: \n");
	printf("please the row number: ");
	scanf("%d",&departureRow);
	printf("please the coloumn number: ");
	scanf("%d",&departureColoumn);
	/*if the entered choice is a car driving, the user has to input a valid location
	i.e. a car location , and vice versa for the walking mood*/
	if(choice==0 && arr[departureRow][departureColoumn]!=0 || choice==1 && arr[departureRow][departureColoumn]!=1)
	{
		printf("Wrong input, please try again!\n");
		goto input1; /*indicates a rong input location from the user , hence he will be
		asked to enter a new location*/
	}
	else
	{
		input2:/*This input declares the need for the destination location
		printf("please enter your destination: ");*/
		scanf("%d %d",&destinationRow,&destinationColoumn);
		/*if the entered choice is a car driving, the user has to input a valid location
		i.e. a car location , and vice versa for the walking mood*/
		if (choice==0 && arr[destinationRow][destinationColoumn]!=0 || choice==1 && arr[destinationRow][destinationColoumn]!=1)
			{
				printf("wrong input, please try again!\n");
				goto input2;/*indicates a rong input location from the user , hence he will be
				asked to enter a new location*/
			}
	}
}
/*The function is reponsible for filling the board with a random numbers(0,1)*/
void fill_Random (u8 arr[BOARDROWS][BOARDCOLOUMNS], u8 max)
{
	srand(time(0)); /*to get the seed of the rand function used ton generate the randm numbers*/
	for (u8 i=0 ; i<BOARDROWS ; i++)
		for(u8 j=0 ; j<BOARDCOLOUMNS ; j++)
			arr[i][j]=rand()% max;
}

/*The function is used to display the board on the console*/
void print(u8 arr[BOARDROWS][BOARDCOLOUMNS])
{
	printf("   ");
	for (int i =0 ; i<BOARDROWS ; i++)
		printf("%d ",i);
	printf("\n");
	printf("  ");
	for (int i =0 ; i<BOARDROWS+1 ; i++)
		printf("--");
	printf("\n");
	/*printing the main board here*/
	for (u8 i=0 ; i<BOARDROWS ; i++)
	{
		printf("%d",i );
		printf("| ");
		for(u8 j=0 ; j<BOARDCOLOUMNS ; j++)
			printf("%d ",arr[i][j]);
		printf("|");
		printf("%d\n",i );
	}
	printf("  ");
	for (int i =0 ; i<BOARDROWS+1 ; i++)
		printf("--");
	printf("\n");
	printf("   ");
	for (int i =0 ; i<BOARDROWS ; i++)
		printf("%d ",i);
	printf("\n");
}

/*This function to determine the mode the user shall be using during the program
The user do have two options to chose form :
1- The first for the walking mode , which implies the number 0 in the choice slot
2- The second for the driving mode , which implies the number 1 in the choice slot
if the user enters any other number but 0 or 1 a message appears to indicate the Invalid
mode choice and he is asked to re-enter option agian using goto optionChoice command , this
will keep running till the user enters a valid choice
*/
u8 options ()
{
	u8 option;
	optionChoice :
	printf("\n");
	printf("0-walking.\n");
	printf("1-driving.\n\n");
	printf("please choose an option:");
	scanf("%d",&option);
	if (option == 0) /*mode for the walking*/
		printf("Your using the walking mode  \n");
	else if (option == 1) /*mode for the driving */
		printf("Your using the driving mode  \n");
	else /* the invalid mode */
	{
		printf("Not valid mode \n");
		goto optionChoice;
	}
	return option;
}
