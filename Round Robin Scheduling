#include<stdio.h>
#include<stdlib.h>
struct node{
   int pid;
   int at;
   int bt;
   int ct;
   int wt;
   int tat;
   int fa;
   int rt;
   int remt;
   int iq;
};

int rq[10];
int front=-1,rear=-1;

void enqueue(int x){
    rq[++rear]=x;
    if(front==-1){
      front=0;
    }
}

int dequeue(){
   if(front==-1)
    return -1;
   else if(front==rear){
     int pd= rq[front];
     front=-1;
     rear=-1;
     return pd;
   }
   else{
     return rq[front++];
   }
}
int alldone(struct node arr[],int n){
     int f=1;
     for(int i=0;i<n;i++){
       if(arr[i].remt!=0){
         f=0;
         break;
       }
     }
     return f;
}

void newprocess(struct node arr[],int t,int n){
   for(int i=0;i<n;i++){
      if(arr[i].at<=t&&arr[i].ct==0&&arr[i].iq==0){
        enqueue(arr[i].pid);
        arr[i].iq=1;
      }
   }
}

void roundrobin(struct node arr[],int n,int qt){
     int time=0,j;
     printf("enter the process details:\n");
     for(int i=0;i<n;i++){
        scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
        arr[i].ct=0;
        arr[i].remt=arr[i].bt;
        arr[i].iq=0;
     }
     
     while(!alldone(arr,n)){
        newprocess(arr,time,n);
        int pd=dequeue();
        if(pd!=-1){
          for(j=0;j<n;j++){
             if(arr[j].pid==pd){
                break;
             }
          }
          if(arr[j].remt==arr[j].bt){
             arr[j].fa=time;
          }
          for(int k=0;k<qt;k++){
             time++;
             arr[j].remt--;
             newprocess(arr,time,n);
             if(arr[j].remt==0){
                arr[j].iq=0;
                break;
             }
         }
         arr[j].ct=time;
         if(arr[j].remt>0){
            enqueue(arr[j].pid);
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
   printf("Process Scheduling Table:\n");
   printf("pid\t at\t bt\t ct\t wt\t tat\t fa\t rt\n");
   for(int i=0;i<n;i++){
      printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t %d\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].wt,arr[i].tat,arr[i].fa,arr[i].rt);
   }
}

void main(){
   int n,qt;
   printf("enter the no of processes:");
   scanf("%d",&n);
   struct node proc[n];
   printf("enter the quantum time:");
   scanf("%d",&qt);
   roundrobin(proc,n,qt);
}
   
     
