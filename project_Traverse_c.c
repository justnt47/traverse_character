#include<stdio.h>  
#include<stdlib.h>  
void create(char);  
void traverse_list();
void search();  
struct node  
{  
    char data;  
    struct node *next;  
};  
struct node *head = NULL;  
void main ()  
{  
    int choice,item,loc;  
    do   
    {  
    	system("cls");
        printf("\n1.Create\n2.Search\n3.Display\n0.Exit\nEnter your choice : ");  
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
	            printf("\nEnter the character\n");  
	            scanf("%s",&item);  
	            create(item);  
	            break;   
            case 2:  
            	search(); 
            	break;
			case 3:
				traverse_list(); 
				break;
            case 0:  
            	exit(0);  
            	break;    
            default:  
            	printf("\nPlease enter valid choice\n");  
        }  
                  
    }while(choice != 0);  
}  
void create(char item)  
{ 
    struct node *ptr = (struct node *)malloc(sizeof(struct node));  
    struct node *temp;  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        ptr->data = item;  
        
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head ;
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        }  
    printf("\nInserted\n");  
    }  
  
}  
void search()  
{  
    struct node *ptr; 
	char item; 
    int i=0,flag=1;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
        getch();
    }  
    else  
    {   
        printf("\nEnter item which you want to search \n");   
        scanf("%s",&item);  
        if(head ->data == item)  
        {  
        printf("item found at location %d",i+1);  
        getch();
        flag=0;  
        return;  
        }  
        else   
        {
		ptr = ptr->next;  
		i++;
        while (ptr != head)  
        {  
            if(ptr->data == item)  
            {  
                printf("item found at location %d ",i+1);  
                getch();
                flag=0;  
                return;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }
		  
        }  
        if(flag != 0)  
        {  
            printf("Item not found\n"); 
			getch(); 
            return;  
        }  
    }     
          
}

void traverse_list()
{
	struct node *temp;
	temp = head;
	if(head == NULL){
		printf("Empty List \n");
		getch();
		return;
	}
	printf("%c \n",temp->data);
	temp = temp->next;
	while(temp != head){
		printf("%c \n",temp->data);
		temp = temp->next;
	}

	getch();
}
