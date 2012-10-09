/** This program is to sort a given set of numbers using bubble sort technique
    Input :unsorted_array
    Output:sorted_array
    Date  :06/10/2012
**/

#include<stdio.h>

void main() {

    int numb_array[10],count,index,index1,temp;
    
    printf("Enter the number of elemnts to be sorted: ");
    scanf("%d",&count);
    printf("Enter the elements to be sorted: ");

    for(index=0;index<count;index++){
        scanf("%d",&numb_array[index]);
    }

    printf("\n The unsorted array is: ");
    
    for(index=0;index<count;index++){
        printf("\n %d ",numb_array[index]);
    }

    for(index=0;index<count-1;index++){
        for(index1=index+1;index1<count;index1++){
            if(numb_array[index]>numb_array[index1]){
                temp=numb_array[index];
                numb_array[index]=numb_array[index1];
                numb_array[index1]=temp;

            }
        }
    }

    printf("\n The sorted elements are: ");

    for(index=0;index<count;index++){
        printf("\n %d",numb_array[index]);
    }
} 
