//balloons.c
//fires an arrow through a row of balloons at different heights. The arrow can only travel downward to hit further balloons. Any balloons that are not hit require another arrow to be fired.
#include <stdio.h>
#include <stdlib.h>

int balloons(const int* arr, int n) {
    int* arrows = calloc(n + 1, sizeof(int));
    //determines how many arrows are needed to hit all balloons.
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

int main() {

    //generate three rows of balloons at different heights
    int arr1[]= { 2, 1, 5, 4, 3 };
    int arr2[]= { 1, 2, 3, 4, 5 };
    int arr3[]= { 4, 5, 2, 1, 4 };

    printf("arrows required: %d\n", balloons(arr1, sizeof(arr1) / sizeof(int)));
    printf("arrows required: %d\n", balloons(arr2, sizeof(arr2) / sizeof(int)));
    printf("arrows required: %d\n", balloons(arr3, sizeof(arr3) / sizeof(int)));

    printf("End of program. Press any key to quit. \n");
    while (getchar() != '\n'); // Clear the input buffer

    return 0;

}