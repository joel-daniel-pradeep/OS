#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node{
   int pid;
   int at;
   int bt;
   int prior;
   int ct;
   int wt;
   int tat;
   int remt;
   int fa;
   int rt;
};
int prior(struct node arr[],int t,int n){  
   int pid=-1;
   int prior=INT_MAX;
   for(int i=0;i<n;i++){
     if((arr[i].prior<prior)&&(arr[i].remt!=0)&&(arr[i].at<=t)){
        pid=arr[i].pid;
        prior=arr[i].prior;
     }
   }
   return(pid);
 }
 int alldone(struct node arr[],int n){  
   int f=1;
   for(int j=0;j<n;j++)
    {
     if(arr[j].remt!=0){
       f=0;
     }
    }
  return(f);
}
void priority(struct node arr[],int n){
   int time=0;
   printf("enter the process details:\n");
   for(int i=0;i<n;i++){
      scanf("%d%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt,&arr[i].prior);
      arr[i].remt= arr[i].bt;
      arr[i].ct=0;
      }
   while(!alldone(arr,n)){
      int pd=prior(arr,time,n);
      if(pd!=-1){
        for(int j=0;j<n;j++)
         {
           if(arr[j].pid==pd){
              arr[j].fa=time;
              time++;
              arr[j].ct=time;
              arr[j].remt--;
              break;
            }
         }
      }
      else{
       time++;
      }
    }
    for(int i=0;i<n;i++){
      arr[i].tat=arr[i].ct-arr[i].at;
      arr[i].wt=arr[i].tat-arr[i].bt;
      arr[i].rt=arr[i].fa-arr[i].at;
    }
    printf("process scheduling table:\n");
    printf("pid\t at\t bt\t prior\t ct\t wt\t tat\t fa\t rt\n");
    for(int i=0;i<n;i++){
       printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].prior,arr[i].ct,arr[i].wt,arr[i].tat,arr[i].fa,arr[i].rt);
    }
}
void main(){
 int n;
 printf("enter the no of processes:\n");
 scanf("%d",&n);
 struct node proc[n];
 priority(proc,n);
}
    
