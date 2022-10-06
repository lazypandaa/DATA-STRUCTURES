#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void addbegin();
void addend();
void addlocation();
void deleteatbegin();
void deleteatend();
void deleteatlocation();
void sort();
void findandreplace();
struct node
{
    int data;
    struct node *next;
}*start=NULL,*current,*newnode,*temp,*previous,*last;
int count()
{
    int d=0;
    temp=start;
    do
    {
        temp=temp->next;
        d++;
    }while(temp->next!=start);
    return d;
}
void main()
{
    int ch;
    do
    {
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
            case 6:deleteatbegin();
            break;
            case 7:deleteatend();
            break;
            case 8:deleteatlocation();
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
        printf("Enter Data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            current=newnode;
            current->next=start;
            last=newnode;
        }
        printf("Enter 0 to exit: ");
        scanf("%d",&ch);
    }while(ch!=0);
}
void display()
{
    if(start==NULL)
        printf("The list is empty\n");
    else
    {
        temp=start;
        printf("Elements are: \n");
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=start);
    }
}
void addbegin()
{
    newnode=(struct node * )malloc(sizeof(struct node));
    printf("Enter Data; ");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
        start=newnode;
        start->next=start;
    }
    else
    {
        newnode->next=start;
        start=newnode;
        last->next=start;
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
        current->next=start;
    }
    else
    {
        last->next=newnode;
        newnode->next=start;
        last=newnode;
    }
}
void addlocation()
{
    int loc,i;
    printf("Enter Location: ");
    scanf("%d",&loc);
    if(loc>count()+1||loc<0)
        printf("inserton not possible\n");
    else if(loc==1)
        addbegin();
    else if(loc>count())
        addend();
    else
    {
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("Enter Data: ");
    scanf("%d",&newnode->data);
    current=start;
    for(i=1;i<loc;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=newnode;
    newnode->next=current;
    }
}
void deleteatbegin()
{
    if(start==NULL)
    printf("Deletion Not possible\n");
    else
    {
    temp=start;
    start=start->next;
    free(temp);
    last->next=start;
    }
}
void deleteatend()
{
    if(start==NULL)
    printf("Deletion not possible\n");
    else
    {
    temp=start;
    while(temp->next->next!=start)
        temp=temp->next;
    current=temp->next;
    free(current);
    last=temp;
    temp->next=start;
    }
}
void deleteatlocation()
{
    int loc,i;
    printf("Enter Loaction: ");
    scanf("%d",&loc);
    if(loc>count()+1||loc<0)
        printf("Deletion not possible\n");
    else if(loc==1)
        deleteatbegin();
    else if(loc>=count())
        deleteatend();
    else
    {
        current=start;
        for(i=1;i<loc;i++)
        {
            previous=current;
            current=current->next;
        }
    previous->next=current->next;
    free(current);
    }
}
void sort()
{
    int d;
    if(start==NULL)
    printf("List is Empty\n");
    else
    {
    for(previous=start;previous!=last;previous=previous->next)
    for(current=previous->next;current!=start;current=current->next)
       if(previous->data>current->data)
       {
            d=previous->data;
            previous->data=current->data;
            current->data=d;
       }
    }
}
void findandreplace()
{
    int old,new;
    if(start==NULL)
    printf("Lis is Empty\n");
    else
    {
        printf("Enter old: ");
        scanf("%d",&old);
        printf("Enter new: ");
        scanf("%d",&new);
        temp=start;
        while(temp->data!=old&&temp!=NULL)
            temp=temp->next;
        if(temp==NULL)
            printf("Element not found\n");
        temp->data=new;
    }
}
