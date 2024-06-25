#include<stdio.h>
#include<stdbool.h>

struct memory{
   int id;
   int size;
   int allocated[30];
   int avail;
   int rem;
};
struct process{
  int id;
  int size;
};
void display(struct memory me[],int m){
  for(int i=0;i<m;i++){
     printf("%d => ",me[i].rem);
   }
   printf("\n\n");
}
void resetMemory(struct memory me[], int m) {
    for(int i = 0; i < m; i++) {
        me[i].avail = 0;
        me[i].rem = me[i].size;
        // Reset allocated array if necessary
        // memset(me[i].allocated, -1, sizeof(me[i].allocated));
    }
}
/*void displayresult(struct memory m[],struct process p[],int m,int p){
    int totalfrag=0;
    printf("Block\t Process ID\tBlock Size\tProcess Size\tMemory Fragmented\n");
    for(int i = 0; i < m; i++){
        if(m[i].allocated == -1){
            printf("Block %d\t Process NIL\t%d\t\tNIL\t\t0\n", m[i].blockId, m[i].size);
        }
        else{
            printf("Block %d\t Process %d\t%d\t\t%d\t\t%d\n",
                   m[i].blockId, p[m[i].allocated].id, m[i].size,
                   p[m[i].allocated].size, m[i].fragmentedSize );
            totalFrag += m[i].fragmentedSize;
        }
    }
    printf("Total Fragmentation = %d\n", totalFrag);
}*/
void firstfit(struct memory me[], struct process pe[], int m, int p){
    display(me,m);
    for(int i = 0; i < p; i++){
        int flag = 0;
        for(int j = 0; j < m; j++){
            if( me[j].rem >= pe[i].size){
                flag = 1;
                me[j].allocated[me[j].avail] = i;
                me[j].avail++;
                me[j].rem = me[j].rem - pe[i].size;
                printf("process %d allocated to memory block %d\n",i,j);
                break;
            }
        }
        if(flag == 0){
            printf("The process %d can't be allocated \n", pe[i].id);
        }
        display(me,m);
    }
    
}
void bestfit(struct memory me[],struct process pe[],int m,int p){
   display(me,m);
    for(int i=0;i<p;i++){
       int min=10000;
       int flag=-1;
       for(int j=0;j<m;j++){
          if((me[j].rem-pe[i].size>=0)&&(me[j].rem-pe[i].size<min)){
             min=me[j].rem-pe[i].size;
             flag=j;
           }
       }
       if(flag!=-1){
         me[flag].allocated[me[flag].avail]=i;
         me[flag].rem=me[flag].rem-pe[i].size;
         me[flag].avail++;
         printf("process %d allocated to memory block %d\n",i,flag);
       }
       else{
         printf("process %d cannot be allocated\n",i);
       }
      display(me,m);
    }
}
void worstfit(struct memory me[],struct process pe[],int m,int p){
  display(me,m);
  for(int i=0;i<p;i++){ 
     int max=0;
     int flag=-1;
     for(int j=0;j<m;j++){
       if((me[j].rem-pe[i].size>=0)&&(me[j].rem-pe[i].size>max)){
         max=me[j].rem-pe[i].size;
         flag=j;
       }
     }
     if(flag!=-1){
       me[flag].allocated[me[flag].avail]=i;
       me[flag].avail++;
       printf("process %d allocated to block %d\n",i,flag);
       me[flag].rem=me[flag].rem-pe[i].size;
     }
     else{
       printf("process %d cannot be allocated\n",i);
     }
   display(me,m);
 }
}
void main(){
  int np,nm,c,ch=1;
  printf("enter the number of memory blocks:\n");
  scanf("%d",&nm);
  printf("enter the number of processes:\n");
  scanf("%d",&np);
  struct memory m[nm];
  struct process p[np];
  printf("enter the block sizes:\n");
  for(int i=0;i<nm;i++){
    m[i].id=i+1;
    scanf("%d",&m[i].size);
    m[i].rem=m[i].size;
    m[i].avail=0;
  }
  printf("enter the process sizes:\n");
  for(int i=0;i<np;i++){
    p[i].id=i+1;
    scanf("%d",&p[i].size);
  }
  while(ch){
  printf("1.firstfit\n");
  printf("2.bestfit\n");
  printf("3.worstfit\n");
  scanf("%d",&c);
  if(c==1){
    firstfit(m,p,nm,np);
  }
  else if(c==2){
    bestfit(m,p,nm,np);
  }
  else if(c==3){
    worstfit(m,p,nm,np);
  }
  else{ 
    printf("wrong option:\n");
  }
  resetMemory(m,nm);
  printf("do you want to continue?0/1");
  scanf("%d",&ch);
}}
