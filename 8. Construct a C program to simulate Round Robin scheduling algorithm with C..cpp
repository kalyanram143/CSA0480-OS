#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void calculateWaitingTurnaroundTime(struct Process processes[], int n) {
    int total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, timeQuantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    int currentTime = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time <= timeQuantum) {
                    currentTime += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = currentTime;
                    completed++;
                } else {
                    currentTime += timeQuantum;
                    processes[i].remaining_time -= timeQuantum;
                }
            }
        }
    }

    calculateWaitingTurnaroundTime(processes, n);
    displayResults(processes, n);

    return 0;
}
