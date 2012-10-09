/** This program is to implement stack.Basic operations implemented here are PUSH,POP and DISPLAY.
Input  :The choice of operation to be performed
Output :Stack is implemented
Date   :04/10/2012
**/

#include<stdio.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top=-1;

void main(){

    int choice;
    int num_choice;
    do{
        printf("Enter the operations to be performed.Please Enter your choice");
        printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.quit\n");
        scanf("%d",&choice);

        switch (choice){
            case 1:push();
                   display();
                   break;

            case 2:pop();
                   break;

            case 3:display();
                   break;

            case 4:exit(0);
                   break;
           default:printf("Please enter a valid choice");
        }

        printf("\n Do you want to continue ,Enter 1 for Yes and 2.No\n");
        fflush(stdin);        
        scanf("%d",&num_choice);
    }while(num_choice ==1);

}

void push(){

    int item;
    if(top>=MAX_SIZE){
        printf("Elements cannot be added-stack overflow");
    }else{
        printf("Enter the element to be inserted");
        scanf("%d",&item);
        top=top+1;
        stack[top]=item;

    }


}

void pop(){

    if(top<0){
        printf("The stack is empty");
    }else{
        printf("The deleted element is %d",stack[top]);
        top=top-1;
    }

}

void display(){

    int i ;
    if(top<0){
        printf("The stack is empty");
    }else{
        printf("The elements in the stack are: ");
        for(i=top;i>=0;i--){
            printf("\n %d ",stack[i]);
        }

    }
}


