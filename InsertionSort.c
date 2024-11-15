#include<stdio.h>
int main(){
    int arr[10];
    int j,i,n,temp;
    printf("Enter the limit of the array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=temp;
    }
    printf("the sorted array is ");
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}