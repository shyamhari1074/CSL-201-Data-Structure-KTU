#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Size 3
int front =-1,rear=-1;
int cq[Size],item;
void enq(){
    if((rear +1)%Size==front){
        printf("THe cq is full");
    }else{
        printf("Enter the element");
        scanf("%d",&item);
        if(front==-1 ){
            front=0;
            rear=0;
        }else{
            rear=(rear +1)%Size;
        }
        cq[rear]=item;
        
    }
}
void deq(){
    if(front==-1 && rear==-1){
        printf("THe cq is empty");
    }else{
        if(front==rear){
            front=-1;
            rear==-1;
        }else{
            cq[front]=0;
        front=(front+1)%Size;
    }
}}
void display()
{
if(front==-1&&rear==-1)
printf("Queue underflow\n");
else
{
   printf("Queue elements:\n");
   
for(int i=0;i<Size;i++)
{
    if(cq[i]==00)
printf("_\t");
else
printf("%d\t",cq[i]);

}
}
}

int main(){
    int choice;
    do{
        printf("\n1.Enqueue\n2.dequeue\n3.Display\n4.Exit\nEnter your choice ==");
        scanf("%d",&choice);
        switch(choice){
            case 1: enq();
            break;
            case 2: deq();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            break;
            default : printf("U DUMB FEllow");
            break;
        }
    }while(1);
}