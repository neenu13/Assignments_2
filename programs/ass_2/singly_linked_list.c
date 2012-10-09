/** This program is to implement singly linked list and its various operations.
Input  : Choice of operation to be performed in linked list
Output : Linked list is implemented
Date   : 07/10/2012
 **/

#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
}*start;


void main() {

    start =NULL;
    int choice,index,count,element,position,num_choice;
    do {

        printf("Enter your choice \n1.Create list \n2.Insert at beginning \n3.Insert at end \n
                4.Insert at a given position\n 5.Delete from beginning\n 6.Delete end\n 7.Delete a given element \n 8.Display");
        scanf("%d",&choice);

        switch(choice) {
            case 1:printf("Enter the number of nodes needed: ");
                   scanf("%d",&count);
                   for(index=0;index<count;index++) {
                       printf("Enter the element: ");
                       scanf("%d",&element);
                       create_list(element);

                   }
                   break;
            case 2:printf("Enter the element to be inserted: ");
                   scanf("%d",&element);
                   insert_begin(element);
                   break;
            case 3:printf("Enter the element to be inserted: ");
                   scanf("%d",&element);
                   insert_end(element);
                   break;
            case 4:printf("Enter the element to be inserted and enter the position");
                   scanf("%d%d",&element,&position);
                   insert_position(element,position);
                   break;
            case 5:delete_first();
                   break;
            case 6:delete_end();
                   break;
            case 7:printf("Enter the element to be deleted");
                   scanf("%d",&element);
                   delete_element(element);
                   break;
            case 8:display();
                   break;


        }
        printf("Do you want to continue 1.yes,2.no");
        scanf("%d",&num_choice);
    }while(num_choice==1);
}



void create_list(int element) {
    
    struct node *curr,*temp;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp->next=NULL;
    if(start==NULL) {
        start=temp;
    }else { 

        curr=start;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=temp;
    }
}

void insert_begin(int element) {
    
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp-> next=NULL;

    if(start==NULL) {
        start=temp;
    }else {
        temp->next=start;
        start=temp;
    }
}

void insert_end(int element){
   
    struct node *temp,*curr;
    int index;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp->next=NULL;
    if(start==NULL) {
        start=temp;
    }else {
        curr=start;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        curr->next=temp;
    }

}

void insert_position(int element,int position) {
    
    struct node *temp,*curr;
    int index;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp->next=NULL;
    curr=start;
    for(index=0;index<position-1;index++) {
        curr=curr->next;
    }
    curr->next=temp;
}

void delete_first() {

    if(start==NULL) {
        printf("The list is empty");
    }else if(start->next==NULL) {
        printf("The deleted element is: %d",start->data);
        start=NULL;
    }else {
        printf("The deleted element is: %d",start->data);
        start=start->next;
    }
}

void delete_end() {

    struct  node *curr,*temp ;
    temp=malloc(sizeof(struct node));
    if(start==NULL) {
        printf("The list is empty");
    }else if(start->next==NULL) {
        printf("The deleted element is: %d",start->data);
        start=NULL;
    }else {
        curr=start;
        while(curr->next!=NULL) {
            temp=curr;
            curr=curr->next;
            printf("The data is %d",curr->data);
        }
        printf("The deleted element is:%d",curr->data);
        temp->next=NULL;
           
        
    }
}

void delete_element(int element) {
    
    struct node *curr,*temp;
    int flag;
    if(start==NULL) {
        printf("The list is empty");
    }else if(start->data==element) {
        printf("The deleted element is: %d",start->data);
        start=start->next;
    }else {
        curr=start;
        while(curr->next!=NULL) {
            flag=0;
            temp=curr->next->next;
            if(curr->next->data==element) {
                flag=1;
                printf("The deleted element is: %d",curr->next->data);
                curr->next=temp;
                break;
            }

        }
        if(flag=0) {
            printf("The element to be deleted is not present in the list");
        }
    }
}

    void display() {

        struct node*temp;
        if(start==NULL) {
            printf("The list is empty");
        }
        else {
            printf("The elements in the list are:\t");
            temp=start;
            while(temp!=NULL) {
                printf("%d\n",temp->data);
                temp=temp->next;
            }

        }
    }
