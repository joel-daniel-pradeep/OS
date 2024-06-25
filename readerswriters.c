#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t wrt;
pthread_mutex_t mutex;
int x=1,readcount=0;

void reader(void *args){
    int n=rand()%5;
    sleep(n);
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount==1)
      sem_wait(&wrt);
    pthread_mutex_unlock(&mutex);
    
    printf("reader %d reads %d ",*((int*)args),x);
    
    pthread_mutex_lock(&mutex);
    readcount--;
    
    if(readcount==0)
       sem_post(&wrt);
       
    pthread_mutex_unlock(&mutex);
}

void writer(void *args){
    int n=rand()%5;
    sleep(n);
    sem_wait(&wrt);
    x*=2;
    printf("writer %d writes %d",*((int *)args),x);
    sem_post(&wrt);
}

void main(){
   int nw,nr;
   printf("enter the no of readers:");
   scanf("%d",&nr);
   printf("enter the no of writers:");
   scanf("%d",&nw);
   pthread_t w[nw],r[nr];
   sem_init(&wrt,0,1);
   pthread_mutex_init(&mutex,NULL);
   int a[20];
   for(int i=0;i<20;i++){
      a[i]=i+1;
   }
   for(int i=0;i<nw;i++){
      pthread_create(&w[i],NULL,(void *)writer,(void *)&a[i]);
   }
   for(int i=0;i<nr;i++){
      pthread_create(&r[i],NULL,(void *)reader,(void *)&a[i]);
   }
   for(int i=0;i<nw;i++){
      pthread_join(w[i],NULL);
   }
   for(int i=0;i<nr;i++){
      pthread_join(r[i],NULL);
   }
   sem_destroy(&wrt);
   pthread_mutex_destroy(&mutex);
}
