/** This program is to sort a given set of numbers using Insertion sort technique
    Input :numb_array,this array is unsorted
    Output:numb_array,this array is sorted
    Date  :06/10/2012
**/

#include<stdio.h>

void main() {

    int numb_array[10],count,index,index1,temp;
    
    printf("Enter the number of elemnts to be sorted: ");
    scanf("%d",&count);
    printf("Enter the elements to be sorted: ");

    for(index=0;index<count;index++) {
        scanf("%d",&numb_array[index]);
    }

    printf("\n The unsorted array is: ");
    
    for(index=0;index<count;index++) { 
        printf("\n %d ",numb_array[index]);
    }

    for(index=1;index<count;index++) {
        temp=numb_array[index];
        index1=index-1;
        while(index1>=0 && numb_array[index1]>temp) {
            numb_array[index1+1]=numb_array[index1];
            index1=index1-1;
        }        
        numb_array[index1+1]=temp;
   }

    printf("\n The sorted elements are: ");

    for(index=0;index<count;index++) {
        printf("\n %d",numb_array[index]);
    }
} 
