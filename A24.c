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
