#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *previous,*next;
};
struct node *start=NULL,*newnode,*temp,*previous,*current,*last;
void create();
void display();
void addbegin();
void addend();
void addlocation();
void deletebegin();
void deleteend();
void deletelocation();
void sort();
void findandreplace();
int count()
{
    int d=0;
    temp=start;
    do
    {
    	temp=temp->next;
    	d++;
    }while(temp!=start);
    return d;
}
void main()
{
    int ch;
    do{
	printf("\n1.Create,2.Display,3.addbegin,4.addend,5.addlocation,6.deleteatbegin,7.deleteatend,8.deleteatlocation,9.sort,10.findandreplace,11.exit\n");
    printf("\nEnter Your choice:");
    scanf("%d",&ch);
	switch(ch)
	{
	    case 1:create();
	    break;
	    case 2:display();
	    break;
	    case 3:addbegin();
	    break;
	    case 4:addend();
	    break;
	    case 5:addlocation();
	    break;
	    case 6:deletebegin();
	    break;
	    case 7:deleteend();
	    break;
	    case 8:deletelocation();
	    break;
	    case 9:sort();
	    break;
	    case 10:findandreplace();
	    break;
	    case 11:exit(1);
	    break;
	}
	if(ch!=1&&ch!=2&&ch!=11)
            display();
    }while(ch!=11);
}
void create()
{
	int ch;
	do
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->previous=NULL;
		if(start==NULL)
		{
			start=newnode;
			current=newnode;
			last=newnode;
		}
		else
		{
			current->next=newnode;
			newnode->previous=current;
			current=newnode;
			last=newnode;
			last->next=start;
			start->previous=last;
		}
	printf("Enter 0 to exit: ");
	scanf("%d",&ch);
	}while(ch!=0);
}
void display()
{
	if(start==NULL)
		printf("The List Is empty");
	else
	{
		temp=start;
		do
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}while(temp!=start);
	}
}
void addbegin()
{
	newnode= (struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
		current=newnode;
		last=newnode;
	}
	else
	{
		newnode->next=start;
		start->previous=newnode;
		start=newnode;
		last->next=start;
		start->previous=last;
	}
}
void addend()
{
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	if(start==NULL)
	{
		start=newnode;
		current=newnode;
		last=newnode;
	}
	else
	{
		temp=start;
		while(temp->next!=start)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->previous=temp;
		last=newnode;
		last->next=start;
		start->previous=last;
	}
}
void addlocation()
{
	int loc,i;
	printf("Enter Location; ");
	scanf("%d",&loc);
	if(loc>count()+1||loc<=0)
		printf("Insertion is not possible\n");
	else if(loc==1)
		addbegin();
	else if(loc>=count())
		addend();
	else
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter your Data");
		scanf("%d",&newnode->data);
		current=start;
		for(i=1;i<loc;i++)
		{
			previous=current;
			current=current->next;
		}
		previous->next=newnode;
		newnode->previous=previous;
		newnode->next=current;
		current->previous=newnode;
	}
}
void deletebegin()
{
	if(start==NULL)
		printf("The list is empty");
	else
	{
		temp=start;
		start=start->next;
		free(temp);
		start->previous=last;
		last->next=start;
	}
}
void deleteend()
{
	if(start==NULL)
		printf("The list is empty");
	else
	{
		temp=start;
		while(temp->next->next!=start)
		{
			temp=temp->next;
		}
		current=temp->next;
		free(current);
		temp->next=start;
		start->previous=temp;
		last=temp;
	}
}
void deletelocation()
{
	int loc,i;
	printf("Enter Location: ");
	scanf("%d",&loc);
	if(loc>count()+1||loc<=0)
		printf("Deletion not poosible");
	else if(loc==1)
		deletebegin();
	else if(loc>=count())
		deleteend();
	else
	{
		current=start;
		for(i=1;i<loc;i++)
		{
			previous=current;
			current=current->next;
		}
		previous->next=current->next;
		current->previous=previous->next;
		free(current);
	}
}
void sort()
{
	int d;
	for(previous=start;previous!=last;previous=previous->next)
		for(current=previous->next;current!=start;current=current->next)
			if(previous->data>current->data)
			{
				d=previous->data;
				previous->data=current->data;
				current->data=d;
			}
}
void findandreplace()
{
	int old,newvalue;
	if(start==NULL)
		printf("The list is empty");
	else
	{
		printf("Enter old: ");
		scanf("%d",&old);
		printf("Enter new: ");
		scanf("%d",&newvalue);
		temp=start;
		while(temp->data!=old&&temp!=NULL)
		{
			temp=temp->next;
		}
		if(temp->data==old)
			temp->data=newvalue;
		else
			printf("Element not found");
	}
}
