#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int process_id;
    int burst_time;
    int remaining_time;
    bool completed;
};

void swap(struct Process *a, struct Process *b)
{
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}
void sort_by_remaining_time(struct Process processes[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].remaining_time > processes[j + 1].remaining_time)
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void srtf(struct Process processes[], int n)
{
    int current_time = 0;

    while (true)
    {
        int shortest = -1;
        // find the process with the shortest remaining time

        for (int i = 0; i < n; i++)
        {
            if (!processes[i].completed && processes[i].burst_time > 0 && (shortest == -1 || processes[i].remaining_time < processes[shortest].remaining_time))
            {
                shortest = i;
            }
        }
        if (shortest == -1)
        {
            // all processes are completed
            break;
        }
        // execute the process
        processes[shortest].burst_time--;
        processes[shortest].remaining_time--;

        printf("Time %d: Process %d\n", current_time, processes[shortest].process_id);
        current_time++;
        // check if the process is completed
        if (processes[shortest].burst_time == 0)
        {
            processes[shortest].completed = true;
        }
        // sort processes based on remaining time for the next iteration
        sort_by_remaining_time(processes, n);
    }
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[6];

    // input burst times for each process

    for (int i = 0; i < n; i++)
    {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d:", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }
    // sort processes based on burst time for the initial state
    sort_by_remaining_time(processes, n);

    // execute processes using SRTF
    srtf(processes, n);
    return 0;
}