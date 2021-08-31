#include <stdio.h>
#include <stdlib.h>
 //this program based on user input.
 //any variable with 1 refers to stack
 //any variable with 2 refers to queue
void push1(int);
void push2(int);
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();
 //st1==>stack..........st2==>queue
 //top1==>stack.........top2==>queue
int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
 
int main()
{
    
 
    
    create();
    enqueue();
	enqueue();    
    enqueue();
    enqueue();
	dequeue();
	display();
	
    
            
    
}
 
/*Function to create a queue*/
void create()
{
    top1 = top2 = -1;
}
 
/*Function to push the element on to the stack*/
void push1(int data)
{
    st1[++top1] = data;
}
 
/*Function to pop the element from the stack*/
int pop1()
{
    return(st1[top1--]);
}
 
/*Function to push an element on to stack*/
void push2(int data)
{
    st2[++top2] = data;
}
 
/*Function to pop an element from th stack*/
 
int pop2()
{
    return(st2[top2--]);
}
 
/*Function to add an element into the queue using stack*/
void enqueue()
{
    int data, i;
 
    printf("Enter data into queue: ");
    scanf("%d", &data);
    push1(data);
    count++;
}
 
/*Function to delete an element from the queue using stack*/
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
/*Function to display the elements in the stack*/
 
void display()
{
    int i;
 
    for (i = 0;i <= top1;i++)
    {
        printf("queue num %d : %d \n",i, st1[i]);
    }
}
