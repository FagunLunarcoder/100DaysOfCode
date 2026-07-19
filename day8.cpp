// #include <iostream>
// using namespace std;

// long long power(long long a, long long b) {
//     if (b == 0)
//         return 1;

//     long long half = power(a, b / 2);

//     if (b % 2 == 0)
//         return half * half;
//     else
//         return a * half * half;
// }

// int main() {
//     long long a, b;
//     cin >> a >> b;

//     cout << power(a, b) << endl;

//     return 0;
// }





#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    int n;
    cin >> n;

    if (isPowerOfTwo(n))
        cout << "true";
    else
        cout << "false";

    return 0;
}