#include <stdio.h>

#define MAX_SIZE 1000 // максимальный размер массива

int main() {
    int arr[] = {1,-1,2, };
    int n = sizeof(arr) / sizeof(arr[0]);
    int count[MAX_SIZE] = {0}; // массив для подсчета количества чисел


    for (int i = 0; i < n; i++) {
        count[arr[i] + MAX_SIZE/2]++;
    }

    for (int i = 0; i <= MAX_SIZE/2; i++) {
        if (count[MAX_SIZE/2 + i] > 0 && count[MAX_SIZE/2 - i] > 0) {
            int min_count = count[MAX_SIZE/2 + i] < count[MAX_SIZE/2 - i] ? count[MAX_SIZE/2 + i] : count[MAX_SIZE/2 - i];
            count[MAX_SIZE/2 + i] -= min_count;

            count[MAX_SIZE/2 - i] -= min_count;
        }
        if (count[MAX_SIZE/2 + i] > 0) {
            printf("%d: %d\n", i, count[MAX_SIZE/2 + i]);
        }
        if (i != 0 && count[MAX_SIZE/2 - i] > 0) {
            printf("%d: %d\n", -i, count[MAX_SIZE/2 - i]);
        }
    }

    return 0;
}
