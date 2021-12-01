#include <stdlib.h>
#include <stdio.h>

#define N 10

int main() {
    int increased = 0;
    int size = 0;
    int max_size = N;
    int tmp = 0;
    int* entries = malloc(sizeof(int) * max_size);

    while (scanf("%d", &tmp) == 1)
    {
        if(tmp >= max_size)
            entries = realloc(entries, sizeof(int) * (max_size *= 2));

        entries[size++] = tmp;
    }

    // Task 1
    for(int i = 1; i < size; i++)
        if(entries[i] > entries[i - 1])
            increased++;

    printf("Task 1 Answer: %d\n", increased);

    // Task 2
    increased = 0;

    for(int i = 5; i < size; i++) {
        int curr = entries[i] + entries[i - 1] + entries[i - 2];
        int prev = entries[i - 1] + entries[i - 2] + entries[i - 3];

        if(curr > prev)
            increased++;
    }
    printf("Task 2 Answer: %d\n", increased);                    
}