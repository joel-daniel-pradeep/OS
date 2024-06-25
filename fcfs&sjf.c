#include<stdio.h>
#include<unistd.h>
#include<limits.h>
struct node{
    int pid;
    int at;
    int bt;
    int ct;
    int wt;
    int tat;
    };
int firstone(struct node arr[],int t,int n){
    int min=INT_MAX;
    int pid=-1;
    for(int i=0;i<n;i++){a
       if((arr[i].at<min)&&(arr[i].ct==0)&&(arr[i].at<=t))
       {
        min=arr[i].at;
        pid=arr[i].pid;
       }
    }
    return(pid);
 }
int shortfirst(struct node arr[],int t,int n){
    int min=INT_MAX;
    int pid=-1;
    for(int i=0;i<n;i++){
       if((arr[i].bt<min)&&(arr[i].ct==0)&&(arr[i].at<=t)){
           pid=arr[i].pid;
           min=arr[i].bt;
       }
    }
    return(pid);
}

int alldone(struct node arr[],int n){
    int f=1;
    for(int i=0;i<n;i++){
        if(arr[i].ct==0){
            f=0;
        }
    }
    return(f);
}
void fcfs(struct node arr[],int n){
    int time=0;
    printf("enter the arress details:\n");
    for(int i=0;i<n;i++){
          scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
          arr[i].ct=0;}
    while(!alldone(arr,n)){
        int np=firstone(arr,time,n);
        if(np!=-1){
             for(int j=0;j<n;j++){
                if(arr[j].pid==np){
                   arr[j].ct=time+arr[j].bt;
                   time+=arr[j].bt;
                   arr[j].tat=arr[j].ct-arr[j].at;
                   arr[j].wt=arr[j].tat-arr[j].bt;
                 }
               }
           }
         else{
         time++;
         }
         }
        printf("the arress scheduling table:\n");
   printf("pid\t at\t bt\t ct\t wt\t tat\t\n");
   for(int i=0;i<n;i++){
     printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].wt,arr[i].tat);
   }
}  
void sjf(struct node arr[],int n){
    int time=0;
    for(int i=0;i<n;i++){
        printf("Enter arress id, arrival time and burst time:");
        scanf("%d%d%d",&arr[i].pid,&arr[i].at,&arr[i].bt);
        arr[i].ct=0;
    }
    
    while(!alldone(arr,n)){
        int np = shortfirst(arr,time,n);
        if(np!=-1){
            for(int j=0;j<n;j++){
                if(arr[j].pid==np){
                    time=time+arr[j].bt;
                    arr[j].ct=time;
                    arr[j].tat=arr[j].ct-arr[j].at;
                    arr[j].wt=arr[j].tat-arr[j].bt;
                }
            }
        }
        else{
            time++;
        }    
    }

  
   printf("the arress scheduling table:\n");
   printf("pid\t at\t bt\t ct\t wt\t tat\t\n");
   for(int i=0;i<n;i++){
     printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",arr[i].pid,arr[i].at,arr[i].bt,arr[i].ct,arr[i].wt,arr[i].tat);
   }
}
void main(){
   int c,n;
   printf("enter the number of arresses\n");
   scanf("%d",&n);
   struct node arr[n];
   printf("1.fcfs scheduling:\n");
   printf("2.sjf scheduling \n");
   scanf("%d",&c);
   if(c==1){
     fcfs(arr,n);
   }
   else if(c==2){
     sjf(arr,n);
   }
   else{ 
     printf("wrong option");
    }
} 
 
 
 
 
 
