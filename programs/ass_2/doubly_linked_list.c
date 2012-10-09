/** This program is to implement singly linked list and its various operations.
Input  :Choice of operation to be done in doubly linked list
Output :Doubly linked list is formmed
Date   :08/10/2012
 **/

#include<stdio.h>
#include<malloc.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*start;


void main() {

    start =NULL;
    int choice,index,count,element,position,num_choice;
    do {

        printf("Enter your choice\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning\n");
        printf("\n4.Delete end\n5.Delete a given element\n6.Display");
        scanf("%d",&choice);

        switch(choice) {

            case 1:printf("Enter the element to be inserted: ");
                   scanf("%d",&element);
                   insert_begin(element);
                   break;
            case 2:printf("Enter the element to be inserted: ");
                   scanf("%d",&element);
                   insert_end(element);
                   break;
            case 3:delete_first();
                   break;
            case 4:delete_end();
                   break;
            case 5:printf("Enter the element to be deleted");
                   scanf("%d",&element);
                   delete_element(element);
                   break;
            case 6:display();
                   break;

        }
        printf("Do you want to continue 1.yes,2.no");
        scanf("%d",&num_choice);
    }while(num_choice==1);
}




void insert_begin(int element) {

    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp-> next=NULL;
    temp->prev=NULL;
    if(start==NULL) {
        start=temp;
    }else {
        start->prev=temp;
        temp->next=start;
        start=temp;
    }

}

void insert_end(int element){

    struct node *temp,*curr;
    temp=malloc(sizeof(struct node));
    temp->data=element;
    temp->next=NULL;
    temp->prev=NULL;
    if(start==NULL) {
        start=temp;
    }else {
        curr=start;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        temp->prev=curr;
        curr->next=temp;
    }

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
        start->prev=NULL;
    }
}

void delete_end() {

    struct  node *curr,*temp ;
    if(start==NULL) {
        printf("The list is empty");
    }else if(start->next==NULL) {
        printf("The deleted element is: %d",start->data);
        start=NULL;
    }else {
        curr=start;
        while(curr->next!=NULL) {
            curr=curr->next;
        }
        printf("The deleted element is:%d",curr->data);
        temp=curr->prev;
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
                temp->prev=curr;
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
