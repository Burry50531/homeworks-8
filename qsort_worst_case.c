#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void generate_worst_case(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

void test_qsort_correctness() {
    int arr[] = {5, 3, 1, 4, 2};
    int expected[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++) {
        if (arr[i] != expected[i]) {
            printf("Test failed at index %d\n", i);
            return;
        }
    }
    printf("Test passed!\n");
}

int main() {
    int n = 100000;
    int *arr = malloc(n * sizeof(int));
    clock_t start, end;

    generate_worst_case(arr, n);

    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();

    printf("Time: %.3f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    test_qsort_correctness();

    free(arr);
    return 0;
}
