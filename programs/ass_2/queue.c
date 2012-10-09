/** This program is to implement the basic operations in queue
    input  :The choice of operation to be performed
    Output :queue is implemented
    Date   :04/10/2012
**/

#include<stdio.h>
#define MAX_SIZE 10
int queue[MAX_SIZE];
int front=-1,rear=-1;

void main(){

    int choice;
    int num_choice;
    do{
        printf("Enter the operations to be performed.Please Enter your choice: ");
        printf("\n 1.Insert\n 2.Delete\n 3.DISPLAY\n 4.quit\n");
        scanf("%d",&choice);

        switch (choice){
            case 1:insert();
                   display();
                   break;

            case 2:delete();
                   break;

            case 3:display();
                   break;

            case 4:exit(0);
                   break;

        }

        printf("\n Do you want to continue ,Enter 1 for Yes and 2.No\n");
        fflush(stdin);
        scanf("%d",&num_choice);
    }while(num_choice ==1);

}

void insert(){

    int item;
    if(rear>=MAX_SIZE){
        printf("Elements cannot be added as it exceeds max limit");
    }else{
        if(front==-1){
            front=front+1;
        }
        printf("Enter the element to be inserted");
        scanf("%d",&item);
        rear=rear+1;
        queue[rear]=item;

    }


}

void delete(){

    if(front<0){
        printf("The queue is empty");
    }else if(front==rear){
        printf("The deleted element is %d",queue[front]);
                front=-1;
                rear=-1;
    }else{
        printf("The deleted element is %d",queue[front]);
        front=front+1;
    }

}

void display(){

    int i ;
    if((front==-1)||(rear==-1)){
        printf("The queue is empty");
    }else{
        printf("The elements in the queue are: ");
        for(i=front;i<=rear;i++){
            printf("\n %d ",queue[i]);
        }

    }
}


