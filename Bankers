#include<stdio.h>
int max[10][10],need[10][10],allocated[10][10],avail[10],temp[10];
int np,nr;
void readmatrix(int m[][10]){
  for(int i=0;i<np;i++){
     for(int j=0;j<nr;j++){
       scanf("%d",&m[i][j]);
     }
  }
}
void printtable(int m[][10]){
  printf("/n/tPROCESS\t\n");
  for(int i=0;i<np;i++){
    printf("\tP%d\t",i);
    for(int j=0;j<nr;j++){
      printf(" %d ",m[i][j]);
    }
    printf("\n");
  }
}


void banker(){
   int flag,k=0;
   int completed[np],safe[np];
   for(int i=0;i<np;i++){
     completed[i]=0;
   }
   for(int i=0;i<np;i++){
      flag=0;
      if(completed[i]==0){
         for(int j=0;j<nr;j++){
           if(need[i][j]>avail[j]){
             flag=1;
             break;
           }
         }
         if(flag==0){
            completed[i]=1;
            safe[k]=i;
            k++;
            for(int j=0;j<nr;j++){
              avail[j]+=allocated[i][j];
            }
            i=-1;
         }
     }
  }
  flag=0;
  for(int i=0;i<np;i++){
    if(completed[i]==0){
      flag=1;
      printf("System is in deadlock!!\n");
      break;
    }}
    if(flag==0)
    {
      printf("the system is in safe state:\n");
      printf("safe sequence:\t");
      for(int i=0;i<k;i++){
        printf(" P%d ",safe[i]);
      }
    }
  }


void main(){
   printf("enter the no of processes and resources:");
   scanf("%d%d",&np,&nr);
   printf("enter the allocated matrix:");
   readmatrix(allocated);
   printf("enter the max matrix:");
   readmatrix(max);
   printf("enter the avail:");
   for(int i=0;i<nr;i++){
     scanf("%d",&avail[i]);
     temp[i]=avail[i];
   }
   for(int i=0;i<np;i++){
     for(int j=0;j<nr;j++){ 
        need[i][j]=max[i][j]-allocated[i][j];
     }
   }
   printf("allocated matrix:\n");
   printtable(allocated);
   printf("max matrix:\n");
   printtable(max);
   printf("avail:\n");
   printf("need matrix:\n");
   printtable(need);
   for(int i=0;i<nr;i++){ 
     printf(" %d  ",avail[i]);
   }
   banker();
   //resource request
   int c,pid,req[nr],f,i;
   printf("so you have any extra requests?0/1?");
   scanf("%d",&c);
   while(c){
      printf("enter the process id:");
      scanf("%d",&pid);
      f=0;
      printf("enter the request:\n");
      for( i=0;i<nr;i++){
        scanf("%d",&req[i]);
        if(req[i]>need[pid][i]){
           f=1;
        }
        
        if(req[i]>temp[i]){
          f=1;
        }
      }
      if(f==1){
         printf("allocation not possible:\n");
      }
      else{
        need[pid][i]-=req[i];
        avail[i]=temp[i]-req[i];
        allocated[pid][i]+=req[i];
      }
      printf( "\nMAX TABLE>>>>\n" );
        printtable(max);
        printf("\nALLOCATED TABLE>>>>\n");
        printtable(allocated);
        printf("\nNEED TABLE>>>>\n");
        printtable(need);
        banker();

        printf("\nDO YOU HAVE ANY EXTRA REQUESTS?(0/1):");
        scanf("%d",&c);
    }
    
}

      
