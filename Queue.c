#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
int Q[MAXSIZE];
int front =-1;
int rear=-1;
int item;
void dequeue(){
    if(front==rear){
        printf("The quueue is empty,underflow condition\n");
        
        }
        else{
            front++;
        }
        
}
void Enqueue(){
    if(rear==MAXSIZE-1){
        printf("The QUEUE is full,overflow condition\n");
    } else{
        Q[++rear]=item;
        
    }
}
void Display(){
    if(front==rear){
        printf("the queue is empty underflow condition\n");
    }else{
    printf("The elements of the queue are:\n");
    for(int i=front+1;i<=rear;i++){
        printf("%d\t",Q[i]);}
    }
}
int main(){
    int choice;
    while(1)
{
    printf("\n1.ENqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice :");
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter the element to be Enqueued::");
        scanf("%d",&item);
        Enqueue(item);
        break;
        case 2: dequeue();
        break;
        case 3: Display();
        break;
        case 4: return 0;
        break;
        default: printf("You dumb fellow");
        break;
    }
}return 0;
}