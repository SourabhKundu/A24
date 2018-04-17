#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
struct que_data
{
    int priority;
    int burst_time;
    int remain_time;
    int ar_time;
};


struct que_data que1[4],que2[4];
int premain,rremain,n[2],total_burst[2],remain_total_burst[2],min_ar[2];

void input_data(struct que_data a[],int size,int loc)
{
    int sum=0,min=10000,pri=0;
    for(int i=0;i<size;i++)
    {
        printf("for process no. %d :- ",i+1);
        scanf("%d %d %d",&a[i].priority,&a[i].ar_time,&a[i].burst_time);
        a[i].remain_time=a[i].burst_time;
        sum+=a[i].burst_time;
        if(a[i].ar_time<min)
        {
            min=a[i].ar_time;
            pri=a[i].priority;
        }
        
    }
    total_burst[loc]=sum;
    remain_total_burst[loc]=total_burst[loc];
    min_ar[loc]=min;
    printf("%d %d",total_burst[loc],min_ar[loc]);

}
int time_quantum=4;
int ptime,pcount,premain;
int intime=1;
void priority_process()
{

    printf("\n\npriority processs are running\n");
    
    printf("\n\nprocess no\t|before burst time\t|process remaining time\n"); 

    while(total_burst[0]!=0)
    {
        int flag=0;
        int prty=1000;
        for(int i=0;i<n[0];i++)
        {
            if(intime>=que1[i].ar_time)
            if(que1[i].priority<prty && que1[i].remain_time>0)
            {
                prty=que1[i].priority;
                pcount=i;
            }
        }
            printf("\npro%d\t\t %d\t\t",pcount+1,que1[pcount].remain_time);
         
            if(que1[pcount].remain_time<=time_quantum && que1[pcount].remain_time>0) 
            { 
                intime+=que1[pcount].remain_time; 
                total_burst[0]-=que1[pcount].remain_time;
                que1[pcount].remain_time=0; 
                flag=1; 
            } 
            else if(que1[pcount].remain_time>0) 
            { 
                que1[pcount].remain_time-=time_quantum; 
                total_burst[0]-=time_quantum;
                
                intime+=time_quantum; 
            } 

             printf("\t%d\n",que1[pcount].remain_time);

            if(que1[pcount].remain_time==0 && flag==1) 
            { 
                printf("process %d terminated\n",pcount+1);
            
                flag=0; 
            } 
            
       
    }
    
}
