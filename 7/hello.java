import java.util.Scanner;

public class hello {
    static int[] arrivalTime = new int[10], burstTime = new int[10];
    static int size;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of processes (max 10): ");
        size = scanner.nextInt();
        System.out.println("Enter arrival time and burst time for each process:");
        for (int i = 0; i < size; i++) {
            System.out.print("Process " + (i + 1) + " - Arrival Time: ");
            arrivalTime[i] = scanner.nextInt();
            System.out.print("Process " + (i + 1) + " - Burst Time: ");
            burstTime[i] = scanner.nextInt();
        }
        System.out.print(
                "Select a scheduling algorithm:\n1. Round Robin\n0. Shortest Remaining Time First\nEnter your choice: ");
        int choice = scanner.nextInt();
        if (choice == 1) {
            System.out.print("Enter time quantum: ");
            int quantum = scanner.nextInt();
            executeRoundRobin(quantum);
        } else if (choice == 0) {
            executeSRTF();
        } else {
            System.out.println("Invalid choice!");
        }
    }

    public static void executeRoundRobin(int quantum) {
        int[] remainingTime = new int[size], waitingTime = new int[size], turnaroundTime = new int[size];
        boolean[] completed = new boolean[size];
        System.arraycopy(burstTime, 0, remainingTime, 0, size);
        int currentTime = 0;
        while (true) {
            boolean allProcessesCompleted = true;
            for (int i = 0; i < size; i++) {
                if (remainingTime[i] > 0) {
                    allProcessesCompleted = false;
                    if (remainingTime[i] > quantum) {
                        currentTime += quantum;
                        remainingTime[i] -= quantum;
                    } else {
                        currentTime += remainingTime[i];
                        waitingTime[i] = currentTime - arrivalTime[i] - burstTime[i];
                        remainingTime[i] = 0;
                        completed[i] = true;
                    }
                }
            }
            if (allProcessesCompleted)
                break;
        }
        calculateAndDisplayResults(waitingTime, burstTime, turnaroundTime);
    }

    public static void executeSRTF() {
        int[] remainingTime = new int[size], waitingTime = new int[size], turnaroundTime = new int[size];
        boolean[] completed = new boolean[size];
        System.arraycopy(burstTime, 0, remainingTime, 0, size);
        int currentTime = 0;
        while (true) {
            int shortestRemainingTime = Integer.MAX_VALUE, shortestIndex = -1;
            boolean allProcessesCompleted = true;
            for (int i = 0; i < size; i++) {
                if (arrivalTime[i] <= currentTime && remainingTime[i] > 0) {
                    allProcessesCompleted = false;
                    if (remainingTime[i] < shortestRemainingTime) {
                        shortestRemainingTime = remainingTime[i];
                        shortestIndex = i;
                    }
                }
            }
            if (allProcessesCompleted)
                break;
            currentTime++;
            remainingTime[shortestIndex]--;
            if (remainingTime[shortestIndex] == 0) {
                completed[shortestIndex] = true;
                waitingTime[shortestIndex] = currentTime - arrivalTime[shortestIndex] - burstTime[shortestIndex];
            }
        }
        calculateAndDisplayResults(waitingTime, burstTime, turnaroundTime);
    }

    public static void calculateAndDisplayResults(int[] waitingTime, int[] burstTime, int[] turnaroundTime) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int[] finishingTime = new int[size];
    for (int i = 0; i < size; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
        finishingTime[i] = arrivalTime[i] + turnaroundTime[i];
    }
    System.out.println("Process\tArrival Time\tBurst Time\tWaiting Time\tFinishing Time\tTurnaround Time\tTurnaround Time / Burst Time");
    for (int i = 0; i < size; i++) {
        double turnaroundToBurstRatio = (double) turnaroundTime[i] / burstTime[i];
        System.out.println(
                (i + 1) + "\t\t" + arrivalTime[i] + "\t\t" + burstTime[i] + "\t\t" + waitingTime[i] + "\t\t" +
                finishingTime[i] + "\t\t" + turnaroundTime[i] + "\t\t" + turnaroundToBurstRatio);
    }
    System.out.println("Average Waiting Time: " + (double) totalWaitingTime / size +
            "\nAverage Turnaround Time: " + (double) totalTurnaroundTime / size);
}

}
