// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int k;
//     cin >> k;

//     int comparisons = 0;

//     for (int i = 0; i < n; i++) {
//         comparisons++;
//         if (arr[i] == k) {
//             cout << "Found at index " << i << endl;
//             cout << "Comparisons = " << comparisons << endl;
//             return 0;
//         }
//     }

//     cout << "Not Found" << endl;
//     cout << "Comparisons = " << comparisons << endl;

//     return 0;
// }



#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n - 1];
    long long sum = 0;

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    long long total = (1LL * n * (n + 1)) / 2;

    cout << total - sum;

    return 0;
}