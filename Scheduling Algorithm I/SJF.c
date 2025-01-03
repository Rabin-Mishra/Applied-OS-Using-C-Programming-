#include <stdio.h>

struct Process
{
    int id;
    int burst_time;
};

void sjfScheduling(struct Process processes[], int n)
{
    // sort processes based in burst time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].burst_time > processes[j + 1].burst_time)
            {
                // swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int completion_time = 0;
    // display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", processes[i].id);
        completion_time += processes[i].burst_time;
        printf("(Completion Time: %d\n)", completion_time);
    }
    printf("\n");
}

int main()
{
    int n = 6;
    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[6];

    // input details of each process
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter the burst time for Process P%d ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // perform SJF scheduling
    sjfScheduling(processes, n);
    return 0;
}