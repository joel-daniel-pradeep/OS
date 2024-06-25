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
  int rt;
  int fa;
};
int prior(struct node arr[],int t,int n){
  int min=INT_MAX;
  int pid=-1;
  for(int i=0;i<n;i++){
      if((arr[i].prior<min)&&(arr[i].at<=t)&&(arr[i].ct==0)){
         pid=arr[i].pid;
         min=arr[i].prior;
      }
  }
  return(pid);
}
int alldone(struct node arr[],int n){ 
   int f=1;
   for(int i=0;i<n;i++){
     if(arr[i].ct==0){
       f=0;
       break;
     }
   }
  return f;
}
void priority(struct node arr[], int n){
  int time=0;
  printf("enter the process details:\n");
  for(int i=0;i<n;i++){
    scanf("%d%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt,&arr[i].prior);
    arr[i].ct=0;
  }
  while(!alldone(arr,n)){ 
    int pid=prior(arr,time,n);
    if(pid!=-1){
      for(int j=0;j<n;j++){
        if(arr[j].pid==pid){
           arr[j].fa=time;
           arr[j].ct=time+arr[j].bt;
           time+=arr[j].bt;
           arr[j].tat=arr[j].ct-arr[j].at;
           arr[j].wt=arr[j].tat-arr[j].bt;
           arr[j].rt=arr[j].fa-arr[j].at;
        }
      }
   }
   else{
     time++;
   }
 }
 printf("process scheduling table:\n");
 printf("pid\t at\t bt\t prior\t ct\t wt\t tat\t fa\t rt\n");
 for(int i=0;i<n;i++){
   printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].prior,arr[i].ct,arr[i].wt,arr[i].tat,arr[i].fa,arr[i].rt);
 }
}

void main(){
 int n;
 printf("enter the no of processesL\n");
 scanf("%d",&n);
 struct node arr[n];
 priority(arr,n);
}
