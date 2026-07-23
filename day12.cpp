// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<int>> a(m, vector<int>(n));

//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             cin >> a[i][j];

//     if (m != n) {
//         cout << "Not a Symmetric Matrix";
//         return 0;
//     }

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (a[i][j] != a[j][i]) {
//                 cout << "Not a Symmetric Matrix";
//                 return 0;
//             }
//         }
//     }

//     cout << "Symmetric Matrix";
//     return 0;
// }




#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                cout << "false";
                return 0;
            }
        }
    }

    cout << "true";
    return 0;
}
