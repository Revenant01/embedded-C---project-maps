#include "stdio.h"
#include "../../STD_TYPES.h"
#include"stdlib.h"
#include<time.h>
const u8 rows =10;
const u8 coloumns = 10;
void fill_random (u8 arr[rows][coloumns], u8 max);
void print(u8 arr[rows][coloumns]);
u8 options();
void main(void)
{
	printf("khalid \n");
	srand(time(0));
	u8 arr[rows][coloumns];
	u8 row1,row2,coloumn1,coloumn2;
	fill_random( arr, 2);
	print(arr);
	u8 choice=options();
	input1:
	printf("please enter your current position: ");
	scanf("%d %d",&row1,&coloumn1);
	if(0==choice && arr[row1][coloumn1]!=0 || 1==choice && arr[row1][coloumn1]!=1)
	{
		printf("wrong input, please try again!\n");
		goto input1;
	}
	else
	{
		input2:
		printf("please enter your destination: ");
		scanf("%d %d",&row2,&coloumn2);
		if (0==choice && arr[row2][coloumn2]!=0 || 1==choice && arr[row2][coloumn2]!=1)
			{
				printf("wrong input, please try again!\n");
				goto input2;
			}
	}
}
void fill_random (u8 arr[rows][coloumns], u8 max)
{
	for (u8 i=0 ; i<rows ; i++)
	{
		for(u8 j=0 ; j<coloumns ; j++)
		{
			arr[i][j]=rand()% max;
		}
	}
}
void print(u8 arr[rows][coloumns])
{
	for (u8 i=0 ; i<rows ; i++)
	{
		for(u8 j=0 ; j<coloumns ; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
u8 options ()
{
	u8 option;
	printf("0-walking.\n");
	printf("1-driving.\n");
	printf("please choose an option:");
	scanf("%d",&option);
	return option;
}
