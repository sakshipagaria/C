//FCFS
#include <stdio.h>

int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter the total number of proesses(max:20): ");
    scanf("%d",&n);
    printf("Enter the burst time: ");
    for(i=0;i<n;i++){
        printf("P[%d]: ",i++);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    
    for (i=1;i<n;i++){
        wt[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
    }
    printf("\n Process \tBurst time \tWaiting time \tTurn around time");
    
    for (i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\nAverage waiting time:%d",avwt);
    printf("\nAverage turn around time:%d",avtat);
    return 0;
}
