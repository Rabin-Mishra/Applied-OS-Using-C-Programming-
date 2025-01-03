#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[])
{
    int wt[6], tat[6];

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = total_wt / n;
    float avg_tat = total_tat / n;

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);
}

int main()
{
    int n = 6;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[6], burst_time[6];

    printf("Enter the burst time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst Time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1;
    }

    findAverageTime(processes, n, burst_time);

    return 0;
}
