#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* next;
	struct node* prev;
	int data;
}node;

typedef struct special_list
{
	node* head;
	node* mid;
	int noe; //noe == number of elements
}sp;

//function to initialize the link-list data structure
void initsp(sp* s)
{
	s->head=NULL;
	s->mid=NULL;
	s->noe=0;
}

void display(sp* s); //display function declaration

//function to perform insertion at the beginning in O(1) time complexity
void insert(sp* s,int x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=s->head;

	if(s->head==NULL)
		s->mid=temp;

	if(s->head!=NULL)
		s->head->prev=temp;

	s->head=temp;

	(s->noe)++;

	if(s->noe!=1 && s->noe%2!=0)
		s->mid=s->mid->prev;

	display(s);
}

//function to perform deletion from the middle in O(1) time complexity
void del(sp* s)
{
		if(s->noe==0)
		{
			printf("Deletion from empty list is not possible ....\n");
			return;
		}
		if(s->noe==1)
		{
			s->head=NULL;
			s->mid=NULL;
			(s->noe)--;
		}
		else
		{
			node* temp=(node*)malloc(sizeof(node));
			temp=s->mid;
			if(temp->prev!=NULL)
				temp->prev->next=temp->next;
			if(temp->next!=NULL)
				temp->next->prev=temp->prev;
			(s->noe)--;
			if((s->noe)%2==0)
				s->mid=temp->next;
			else
				s->mid=temp->prev;

		}

		display(s);
}

//function to display the list
void display(sp* s)
{
	node* temp=(node*)malloc(sizeof(node));
	temp=s->head;
	printf("\nNo. of elements in the list -> %d\n",s->noe);

	printf("current list --\n\n");
	if((s->noe)==0)
	{
		printf("List is empty ....\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}

	printf("\n");
}


int main()
{
	int ch,item;
	char an;
	sp* a=(sp*)malloc(sizeof(sp));
	initsp(a);
	menu:
	system("tput clear");
	printf("----------------- welcome -------------- \n");
	printf("1.Insert item at front\n");
	printf("2.Delete from middle\n");
	printf("3.Print current list\n");
	printf("0.Exit\n");
	printf("\n\nEnter choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
				system("tput clear");
				do
				{
					printf("Enter data : ");
					scanf("%d",&item);
					insert(a,item);
					printf("\nEnter another ?(y/n) : ");
					fflush(stdin);
					scanf(" %c",&an);
				}while(an=='y');
				goto menu;

		case 2:
				system("tput clear");
				do
				{
					del(a);
					printf("\nDelete again ?(y/n) : ");
					fflush(stdin);
					scanf(" %c",&an);
				}while(an=='y');
				goto menu;

		case 3:
				system("tput clear");
				display(a);
				printf("\nEnter anything to go back to menu : ");
				fflush(stdin);
				getchar();
				getchar();
				goto menu;

		case 0:
				exit(1);

		default:
				exit(2);
	}
}

