#include<stdio.h>
#include<stdlib.h>
// linked list node ==> stores a queue entry
struct node {
    int val;
    struct node* next;
};
 
// queue front ==> stores the front node 
// queue rear  ==> stores the last node 
struct Queue {
    struct node *front, *rear;
};
 
// create a new ll node.
struct node* newNode(int N)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = N;
    temp->next = NULL;
    return temp;
}
 
// create an empty queue
struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 
// function to add val N to q
void enQueue(struct Queue* q, int N)
{
    // Create a new LL node
    struct node* temp = newNode(N);
 
    // If queue is empty == new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    // Add the new node at the end of queue & change rear
    q->rear->next = temp;
    q->rear = temp;
}
 
// Function to remove val from given queue q
void deQueue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;
 
    // Store previous front and move front one node ahead
    struct node* temp = q->front;
 
    q->front = q->front->next;
 
    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}

// Driver Program to test anove functions
int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 1);
    enQueue(q, 8);
    deQueue(q);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    deQueue(q);
    printf("Queue Front : %d \n", q->front->val);
    printf("Queue Rear : %d", q->rear->val);
    return 0;
}
