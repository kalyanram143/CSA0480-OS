#include <stdio.h>

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completed;
};

void calculateWaitingTurnaroundTime(struct Process processes[], int n) {
    int total_waiting_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }
}

void displayResults(struct Process processes[], int n) {
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].completed = 0;
    }

    int currentTime = 0;
    int completed = 0;
    
    while (completed < n) {
        int shortestJob = -1;
        int shortestBurstTime = 999999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= currentTime && !processes[i].completed &&
                processes[i].burst_time < shortestBurstTime) {
                shortestJob = i;
                shortestBurstTime = processes[i].burst_time;
            }
        }

        if (shortestJob == -1) {
            currentTime++;
        } else {
            processes[shortestJob].turnaround_time = currentTime + processes[shortestJob].burst_time - processes[shortestJob].arrival_time;
            processes[shortestJob].completed = 1;
            completed++;
            currentTime += processes[shortestJob].burst_time;
        }
    }

    calculateWaitingTurnaroundTime(processes, n);
    displayResults(processes, n);

    return 0;
}
