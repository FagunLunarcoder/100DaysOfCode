// #include <stdio.h>

// int fib(int n) {
//     if (n <= 1)
//         return n;

//     int prev2 = 0, prev1 = 1, curr;

//     for (int i = 2; i <= n; i++) {
//         curr = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     return prev1;
// }

// int main() {
//     int n;
//     scanf("%d", &n);

//     if (n <= 1) {
//         printf("%d", n);
//         return 0;
//     }

//     int a = 0, b = 1, c;

//     for (int i = 2; i <= n; i++) {
//         c = a + b;
//         a = b;
//         b = c;
//     }

//     printf("%d", b);

//     return 0;
// }




#include <stdio.h>

int fib(int n) {
    if (n <= 1)
        return n;

    int prev2 = 0, prev1 = 1, curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", fib(n));

    return 0;
}