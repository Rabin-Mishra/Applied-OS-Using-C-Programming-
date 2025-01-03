#include <stdio.h>
struct Process
{
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, int time_quantum)
{
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (processes[i].remaining_time > 0)
            {
                // execute the process for the time quantum or remaining time ,whichever is smaller
                int execution_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                processes[i].remaining_time -= execution_time;
                current_time += execution_time;

                // Display the execution
                printf("Executing Process P%d for %d units of time.\n", processes[i].id, execution_time);

                if (processes[i].remaining_time == 0)
                {
                    // Process is completed
                    remaining_processes--;
                    printf("Process P%d completed at time %d.\n", processes[i].id, current_time);
                }
            }
        }
    }
}
int main()
{
    int n, time_quantum;
    // input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[6];

    // Input details of each process
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter burst time for Process P%d:", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    // input time quantum
    printf("Enter the time quantum:");
    scanf("%d", &time_quantum);

    // Perform round robin scheduling
    roundRobinScheduling(processes, n, time_quantum);
    return 0;
}