#include <math.h> 
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
 

// Insertion Sort Function
void insertionSort(int array[], int n) 
{ 
    int i, element, j; 
    for (i = 1; i < n; i++)
	 { element = array[i]; j = i - 1; 
	 while (j >= 0 && array[j] > element) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = element; 
    } 
} 
   
// quick Sort Function
void quicksort(int number[100000],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
   
}

int main(){
	
int randArray[100000],randArray1[100000],i;
   
   for(i=0;i<100000;i++) //Generate numbers randomly
     {
	 randArray[i]=rand();
	 randArray1[i]=randArray[i];
	 }    
 printf("array of 100000 random numbers is initialized\n\n\n"); 

// Calculate the time taken by quick sort Function
   clock_t t;
   t = clock();
   quicksort(randArray,0,99999); 
   t = clock() - t;
   double time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate the elapsed time
   
   printf("the array is sorted using quick sort in %f seconds \n", time_taken);
	  
	  
	
// Calculate the time taken by Insertion Sort Function
   clock_t t1;
   t1 = clock();
insertionSort(randArray1,100000);
   t1 = clock() - t1;
   double time_taken1 = ((double)t1)/CLOCKS_PER_SEC; // calculate the elapsed time
   
   printf("the array is sorted using insertion sort in %f seconds \n", time_taken1);
	  
	return 0;
}

