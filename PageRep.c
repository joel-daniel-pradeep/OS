#include<stdio.h>
#include<stdbool.h>

int referenceString[100];
int referenceLength;
int noofframes;
int queue[10];

int inqueue(int val){ 
   int f=0;
   for(int i=0;i<noofframes;i++){
      if(queue[i]==val){
         f=1;
         break;
      }
   }
   return f;
}

void display(){ 
   printf("current frame allocation:- ");
   for(int i=0;i<noofframes;i++){
      if(queue[i]==-1){
        break;
      }
      printf(" %d  ",queue[i]);
   }
   printf("\n");
}

void fifo(){
   int pgfault=0;
   int rear=0;
   for(int i=0;i<noofframes;i++){
      queue[i]=-1;
   }
   for(int i=0;i<referenceLength;i++){
      int val=referenceString[i];
      if(!inqueue(val)){
        queue[rear]=val;
        rear=(rear+1)%noofframes;
        pgfault++;
      }
      display();
   }
   printf("page faults: %d\n",pgfault);
   printf("hit ratio : %d/%d\n",referenceLength-pgfault,referenceLength);
   printf("miss ratio : %d/%d\n",pgfault,referenceLength);
 }
 void lru(){
    int pgfault=0;
    for(int i=0;i<noofframes;i++){
      queue[i]=-1;
    }
    int z=0;
    
    for(int i=0;i<referenceLength;i++){
       int val=referenceString[i];
       if(z<noofframes){
        if(!inqueue(val)){
         queue[z]=val;
         z++;
         pgfault++;
        }
        display();
        continue;
      }
      
      if(!inqueue(val)){
         int temp[noofframes];
         int min=100;
         for(int j=0;j<noofframes;j++){
            int valA=queue[j];
            for(int k=i;k>=0;k--){
               if(referenceString[k]==valA){
                 temp[j]=k;
                 if(k<min){
                    min=k;
                 }
                 break;
              }
           }
       }
       int minindex=0;
       for(int j=1;j<noofframes;j++){
          if(temp[j]<temp[minindex]){
            minindex=j;
          }
       }
       queue[minindex]=val;
       pgfault++;
      }
      display();
    }
    printf("page faults: %d\n",pgfault);
   printf("hit ratio : %d/%d\n",referenceLength-pgfault,referenceLength);
   printf("miss ratio : %d/%d\n",pgfault,referenceLength);
 }
 void optimal(){
   int pgfault=0;
   for(int i=0;i<noofframes;i++){
      queue[i]=-1;
   }
   int z=0;
   for(int i=0;i<referenceLength;i++){
                int val=referenceString[i];
                if(z<noofframes){
                  if(!inqueue(val)){
                  queue[z]=val;
                  z++;
                  pgfault++;
                 }
                 display();
                 continue;
               }
               int max=-1;
               if(!inqueue(val)){
               int temp[noofframes];
               for(int j=0;j<noofframes;j++){
                  int valA=queue[j];
                  int f=0;
                  for(int k=i;k<referenceLength;k++){
                    if(referenceString[k]==valA){
                       temp[j]=k;
                       if(k>max){
                         max=k;
                       }
                       f=1;
                       break;
                    }
                 }
                 if(f==0){
                    temp[j]=referenceLength+1;
                 }
              }
              int maxindex=0;
              for(int j=1;j<noofframes;j++){
                if(temp[j]>temp[maxindex]){
                    maxindex=j;
                }
              }
              queue[maxindex]=val;
              pgfault++;
              
          }
        display();
      }
     printf("page faults: %d\n",pgfault);
   printf("hit ratio : %d/%d\n",referenceLength-pgfault,referenceLength);
   printf("miss ratio : %d/%d\n",pgfault,referenceLength);
 }
 
 void main(){
   int ch=1,c;
   printf("enter the reference string  length :");
   scanf("%d",&referenceLength);
   printf("enter the no of frames:");
   scanf("%d",&noofframes);
   printf("enter the reference string :\n");
   for(int i=0;i<referenceLength;i++){
      scanf("%d",&referenceString[i]);
   }
   while(ch){
     printf("1.FIFO\n2.LRU\n3.OPTIMAL\n");
     scanf("%d",&c);
     if(c==1){
        fifo();
     }
     else if(c==2){
        lru();
     }
     else if(c==3){
        optimal();
     }
     else{
       printf("wrong option:\n");
     }
     printf("do you want to continue??0/1");
     scanf("%d",&ch);
     }
}
                  
   
      
      
