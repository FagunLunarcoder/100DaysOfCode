// #include <stdio.h>

// int main() {
//     int n;
//     scanf("%d", &n);

//     int arr[n];

//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     if (n == 0)
//         return 0;

//     int j = 0; // Points to the last unique element

//     for (int i = 1; i < n; i++) {
//         if (arr[i] != arr[j]) {
//             j++;
//             arr[j] = arr[i];
//         }
//     }

//     // Print unique elements
//     for (int i = 0; i <= j; i++) {
//         printf("%d", arr[i]);
//         if (i < j)
//             printf(" ");
//     }

//     return 0;
// }





#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int j = 0; // Position for next non-zero element

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            if (i != j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d", nums[i]);
        if (i < n - 1)
            printf(" ");
    }

    return 0;
}