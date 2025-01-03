#include <stdio.h>

struct Process
{
    int id;
    int priority;
    int burst_time;
};

void priorityScheduling(struct Process processes[], int n)
{
    // sort processes based on priority
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].priority > processes[j + 1].priority)
            {
                // swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++)
    {
        printf("P%d", processes[i].id);
    }
    printf("\n");
}

int main()
{
    int n;
    // since the ide doesnt detect n as a static constant on the provided input so must be given the size of n as a constant number
    //  Input number of processes
    printf("Enter the number of processes ");
    scanf("%d", &n);

    struct Process processes[6];

    // Input details of each process

    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter the priority for process P%d:", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    // perform priority scheduling
    priorityScheduling(processes, n);

    return 0;
}