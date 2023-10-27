#include <stdio.h>
#include <stdlib.h>

int balloons(const int* arr, int n) {
    int* arrows = calloc(n + 1, sizeof(int));

    for (int i = 0; i < n; i++) {
        int b = arr[i];

        if (arrows[b + 1] > 0) {
            arrows[b + 1]--;
            arrows[b]++;
        } else {
            arrows[b]++;
        }
    }
    
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret += arrows[i];

    }

    free(arrows);
    return ret;

}

int main(int argc, char *argv[]) {

    int arr1[]= { 5, 3, 4, 1, 2 };
    int arr2[]= { 5, 4, 3, 2, 1 };
    int arr3[]= { 1, 5, 3, 2, 4 };
    printf("arrows required: %d\n", balloons(arr1, 1 + sizeof(arr1) / sizeof(int)));
    printf("arrows required: %d\n", balloons(arr2, 1 + sizeof(arr2) / sizeof(int)));
    printf("arrows required: %d\n", balloons(arr3, 1 + sizeof(arr3) / sizeof(int)));
    return 0;

}