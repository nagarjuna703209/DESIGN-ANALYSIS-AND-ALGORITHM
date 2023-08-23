#include <stdio.h>
#include <stdbool.h>

#define N 4  // Number of agents (rows) and tasks (columns)

int minCost = 9999;  // Initialize with a large value

void printSolution(int assignment[N]) {
    printf("Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Agent %d -> Task %d\n", i + 1, assignment[i] + 1);
    }
    printf("Total Cost: %d\n", minCost);
}

bool isSafe(int task, int agent, int assignment[N], int costMatrix[N][N], bool assigned[N]) {
    return !assigned[task] && costMatrix[agent][task] != -1;
}

void branchAndBound(int level, int assignment[N], int costMatrix[N][N], bool assigned[N], int currentCost) {
    if (level == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
            printSolution(assignment);
        }
        return;
    }

    for (int task = 0; task < N; task++) {
        if (isSafe(task, level, assignment, costMatrix, assigned)) {
            assigned[task] = true;
            assignment[level] = task;
            branchAndBound(level + 1, assignment, costMatrix, assigned, currentCost + costMatrix[level][task]);
            assigned[task] = false;
        }
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    
    int assignment[N];  
    bool assigned[N];   // To keep track of assigned tasks
    
    for (int i = 0; i < N; i++) {
        assignment[i] = -1;
        assigned[i] = false;
    }

    branchAndBound(0, assignment, costMatrix, assigned, 0);

    return 0;
}
