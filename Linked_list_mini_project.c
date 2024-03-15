#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void search();
void sort();
void reverse();
void delete_begin();
void delete_end();
void delete_pos();


struct node 
{
    int data;
    struct node *next;
};

struct node *head=NULL;    //Global declaration

int main()
{
int n;
while(1)
{
    printf("\n *********WELCOME TO LINKED LIST MINI PROJECT**********");
    printf("\n 1.create \n");
    printf("\n 2.display \n");
    printf("\n 3.Insert node at the beginning \n");
    printf("\n 4.Insert node at the end \n");
    printf("\n 5.Insert node at specific Position \n");
    printf("\n 6.Search a node Data \n");
    printf("\n 7.Sort the given Linked List \n");
    printf("\n 8.Reverse the given linked list \n");
    printf("\n 9.Delete node from the beginning \n");
    printf("\n 10.Delete node from the end \n");
    printf("\n 11.Delete node from the specified Position \n");
    printf("\n 12.Exit \n");
    printf("\n----------------------------------------------\n");
    printf("Enter Your choice : \t");
    scanf("%d",&n);

    switch(n)
    {
        case 1:
                    create();
                    break;

        case 2:
                    display();
                    break;
        
        case 3:
                    insert_begin();
                    break;

        case 4:
                    insert_end();
                    break;

        case 5:
                    insert_pos();
                    break;

        case 6:
                    search();
                    break;

        case 7:
                    sort();
                    break;

        case 8:
                    reverse();
                    break;

        case 9:
                    delete_begin();
                    break;

        case 10:
                    delete_end();
                    break;

        case 11:
                    delete_pos();
                    break;

        case 12:
                    exit(0);


        default:
                    printf("\n Wrong Choice :\n");


    }

}

    return 0;
}

void create()
{
    struct node *new, *ptr;
    new=(struct node *)malloc(sizeof(struct node));

    printf("Enter The Data \n");
    scanf("%d",&new->data);
    new->next=NULL;

    if(head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;   //traversing 
        }

        ptr->next=new;    //putting the new address data(shuvo) in the temp-next
    }

}

void display()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\n Linked List is Empty : \n");
    }
    else
    {
        ptr=head;
        printf("\n Elements in the Linked list are : \n");
        while (ptr!=NULL)
        {
        printf("%d ",ptr->data);
        ptr=ptr->next;  
        }

    }

}

void insert_begin()
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter Your Beginning node Data \n");
    scanf("%d",&temp->data);
    
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }

}

void insert_end()
{
    struct node *ptr,*new;  
    new=(struct node *)malloc(sizeof(struct node));

    printf("\n Enter Your Ending node Data \n");
    scanf("%d",&new->data);

    new->next=NULL; //Must have to do this either it will give continious garbage Value

    ptr=head;

    if(ptr==NULL)
    {
        head=new;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new;
    }

}


void insert_pos()
{
    struct node *ptr,*new;
    new=(struct node *)malloc(sizeof(struct node));
    printf("\n Enter Your Data \n");
    scanf("%d",&new->data);
    new->next=NULL;

    
    int n;
    printf("\n Enter at which point you want to add your data \n");
    scanf("%d",&n);
    if(n==0)
    {
        new->next=head;
        head=new;
    }
    else
    {
        ptr=head;
        for(int i=0;i<n-1;i++)
        {
            ptr=ptr->next;
        }

    }
        new->next=ptr->next;
        ptr->next=new;

}

void search()
{
    int data;
    struct node *ptr;
    ptr=head;
    printf("\n Enter Your search Elements \n");
    scanf("%d",&data);

    while(ptr!=NULL)
    {
        if(ptr->data==data)
        {
            printf("\n The data is found \n");
            break;
        }
        else
        {
            ptr=ptr->next;
        }
    }
}


void sort()
{
    struct node *ptr,*cpt=NULL;
    int temp;

    ptr=head;
    if(head==NULL)
    {
        printf("\n The Linked List is Empty \n");
    }
    else
    {
        while (ptr->next!=NULL)
        {
            cpt=ptr->next;
            while(cpt!=NULL)
            {
                if(ptr->data>cpt->data)
                {
                    temp=ptr->data;
                    ptr->data=cpt->data;
                    cpt->data=temp;
                }
                    cpt=cpt->next;
            }

            ptr=ptr->next;

        }

            printf("After sorting the elements : ");
            while(head!=NULL)
            {
                printf("%d ",head->data);
                head=head->next;
            }     
    
    }

}


void reverse()
{
    struct node *prev=NULL,*current,*next=NULL;  //Have to assign prev and next equal to NULL otherwise it will give garbage value at the end
    current=head;

    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
        head=prev;

    printf("Reverse data are : \n");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }

}

void delete_begin()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\n The Linked List is Empty \n");
    }
    else
    {
        ptr=head;
        head=head->next;
        printf("\n The deleted element is : %d\t",ptr->data);
        free(ptr);
    }

}

void delete_end()
{
    struct node *temp,*ptr;
    if(head==NULL)
    {
        printf("\n The Linked List Empty \n");
        exit(0);
    }
    else if(head->next==NULL)
    {
        ptr=head;
        head=NULL;       //before was ptr=NULL
        printf("\n The deleted elements is %d : \n",ptr->data);  //before was head->data
        free(ptr);
    }
    else
    {
        ptr=head;       //added this
        while(ptr->next != NULL)  //changed ptr to ptr->next
        {
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=NULL;
        printf("\n The deleted element is: %d \t",ptr->data);   //changed to temp->data to ptr->data
        free(ptr);
    }
}

void delete_pos()
{
    int n;
    struct node *ptr,*temp;

    if(head==NULL)
    {
        printf("\n The Linked list is Empty\n");
        exit(0);
    }
    else
        {
            printf("\n Enter the Position: \n");
            scanf("%d",&n);

            if(n==0)
            {
                ptr=head;
                head=head->next;
                printf("\n The deleted element is: %d\n",ptr->data);
                free(ptr);
            }
            else
            {
                ptr=head;
                for(int i=0;i<n;i++ && ptr->next!=NULL)
                {
                    temp=ptr;
                    ptr=ptr->next;
                }
            }
            temp->next=ptr->next;
            printf("\n The Deleted element is : %d\t",ptr->data);
            free(ptr);
        }
