#include<stdio.h>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void DLL_Append(void);
void DLL_Insert(void);
void DLL_Delete(void);
void DLL_Print(void);


struct node* tempHeaderNodePtr;
struct node* Header;

int main()
{
	int choice;
	//Initialize the LL
	tempHeaderNodePtr = NULL;
	Header = tempHeaderNodePtr;
	do
	{
		printf("Enter the choice as below\n");
		printf(" 1. Append\n 2. Insert\n 3. Delete\n 4. Print\n 5.Exit\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("You have selected To APPEND\n");
				DLL_Append();
				break;
				
			case 2:
				printf("You have selected To INSERT\n");
				DLL_Insert();
				break;
				
			case 3:
				printf("You have selected To DELETE\n");
				DLL_Delete();
				break;
				
			case 4:
				printf("You have selected To PRINT\n");
				DLL_Print();
				break;
			
			case 5:
				printf("You have selected To EXIT\n");
				break;
			
			default:
				printf("You have selected incorrect option, please try again\n");
				break;
				
		}
	}while(choice != 5);
	
	return(0);
}


void DLL_Append(void)
{
	struct node* tempNodePtr;
	
	int newData;
	
	tempHeaderNodePtr = Header;
	
	//Get the new data
	printf("Enter the data to be embedded in node\n");
	scanf("%d", &newData);
	
	//create the memory node from heap
	tempNodePtr = (struct node*)malloc(sizeof(struct node));
	tempNodePtr->next = NULL;
	tempNodePtr->prev = NULL;
	tempNodePtr->data = newData;
	
	//check for existing LL status
	if(tempHeaderNodePtr == NULL)
	{
		tempHeaderNodePtr = tempNodePtr;
		Header = tempHeaderNodePtr;
		printf("Here1\n");
	}
	else
	{
		while(tempHeaderNodePtr->next != NULL)
		{
			tempHeaderNodePtr = tempHeaderNodePtr->next;
			printf("Here_Loop\n");
		}
		
		printf("Here2\n");
		
		tempHeaderNodePtr->next = tempNodePtr;
		tempNodePtr->prev = tempHeaderNodePtr;
	}
}

void DLL_Insert(void)
{
	struct node* tempNodePtr;
	int insertPosition;
	int Reached = 1;
	int newData;
	
	printf("Your have selected to Insert the data in LL\n");
	printf("Enter the position at which you want to insert : starting from 1");
	
	scanf("%d", &insertPosition);
	
	tempHeaderNodePtr = Header;
	
	if(insertPosition == 1)
	{
		//Get the new data
		printf("Enter the data to be embedded in node\n");
		scanf("%d", &newData);
		
		//create the memory node from heap
		tempNodePtr = (struct node*)malloc(sizeof(struct node));
		tempNodePtr->next = NULL;
		tempNodePtr->prev = NULL;
		tempNodePtr->data = newData;
		
		tempHeaderNodePtr->prev = tempNodePtr;		
		tempNodePtr->next = tempHeaderNodePtr;
		
		Header = tempNodePtr;
	}
	else
	{
		//Traverse to the desired position 
		do
		{
			if(insertPosition - 1 == Reached)
			{
				printf("break");
				break;
			}
			printf("No break");
			tempHeaderNodePtr = tempHeaderNodePtr->next;
			Reached++;
		}while(tempHeaderNodePtr != NULL);

		if(tempHeaderNodePtr != NULL)
		{
			//Get the new data
			printf("Enter the data to be embedded in node\n");
			scanf("%d", &newData);
			
			//create the memory node from heap
			tempNodePtr = (struct node*)malloc(sizeof(struct node));
			tempNodePtr->next = NULL;
			tempNodePtr->prev = NULL;
			tempNodePtr->data = newData;
	
			tempNodePtr->next = tempHeaderNodePtr->next;
			tempNodePtr->prev = tempHeaderNodePtr;
			tempHeaderNodePtr->next->prev = tempNodePtr;
			tempHeaderNodePtr->next = tempNodePtr;
		}
		else
		{
			printf("End of LL, check for correct position for insertion\n");
		}
	}
}

void DLL_Delete(void)
{
	struct node* tempNodePtr;
	int deletePosition;
	int Reached = 1;
	
	printf("Your have selected to Delete the data in LL\n");
	printf("Enter the position at which you want to Delete : starting from 1");
	
	scanf("%d", &deletePosition);
	
	
	
	tempHeaderNodePtr = Header;
	
	if(deletePosition == 1)
	{
		tempNodePtr = tempHeaderNodePtr;
		tempHeaderNodePtr = tempHeaderNodePtr->next;
		tempHeaderNodePtr->prev = NULL;
		Header = tempHeaderNodePtr;
		free(tempNodePtr);
	}
	else
	{
		//Traverse to the desired position 
		do
		{
			if(deletePosition - 1 == Reached)
			{
				printf("break");
				break;
			}
			printf("No break");
			tempHeaderNodePtr = tempHeaderNodePtr->next;
			Reached++;
		}while(tempHeaderNodePtr != NULL);

		//position is incorrect
		if(tempHeaderNodePtr == NULL)
		{
			printf("End of LL, check for correct position for insertion\n");
		}
		//position is the last one
		else if(tempHeaderNodePtr->next->next == NULL)
		{
			tempNodePtr = tempHeaderNodePtr->next;
			tempHeaderNodePtr->next = NULL;
			free(tempNodePtr);
		}
		//position is in between
		else
		{
			tempNodePtr = tempHeaderNodePtr->next;
			tempHeaderNodePtr->next = tempHeaderNodePtr->next->next;
			tempHeaderNodePtr->next->prev = tempHeaderNodePtr;
			tempNodePtr = NULL;
			free(tempNodePtr);
		}
		
	}
}

void DLL_Print(void)
{
	tempHeaderNodePtr = Header;
	
	printf("Forward\n\n");
	do
	{
		printf("%d\t", tempHeaderNodePtr->data);
		tempHeaderNodePtr = tempHeaderNodePtr->next;
	}while(tempHeaderNodePtr != NULL);
	printf("\n\n");
	
	
	
	tempHeaderNodePtr = Header;
	do
	{
		tempHeaderNodePtr = tempHeaderNodePtr->next;
	}while(tempHeaderNodePtr->next != NULL);
	
	printf("Reverse\n\n");
	while(tempHeaderNodePtr != NULL)
	{
		printf("%d\t", tempHeaderNodePtr->data);
		tempHeaderNodePtr = tempHeaderNodePtr->prev;
	}
	
	printf("\n\n");
}

