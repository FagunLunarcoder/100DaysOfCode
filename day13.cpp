// #include <iostream>
// using namespace std;

// int main() {
//     int r, c;
//     cin >> r >> c;

//     int matrix[r][c];

//     // Input matrix
//     for (int i = 0; i < r; i++) {
//         for (int j = 0; j < c; j++) {
//             cin >> matrix[i][j];
//         }
//     }

//     int top = 0;
//     int bottom = r - 1;
//     int left = 0;
//     int right = c - 1;

//     while (top <= bottom && left <= right) {

//         // Top row
//         for (int i = left; i <= right; i++)
//             cout << matrix[top][i] << " ";
//         top++;

//         // Right column
//         for (int i = top; i <= bottom; i++)
//             cout << matrix[i][right] << " ";
//         right--;

//         // Bottom row
//         if (top <= bottom) {
//             for (int i = right; i >= left; i--)
//                 cout << matrix[bottom][i] << " ";
//             bottom--;
//         }

//         // Left column
//         if (left <= right) {
//             for (int i = bottom; i >= top; i--)
//                 cout << matrix[i][left] << " ";
//             left++;
//         }
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    if (matrix.empty())
        return ans;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {

        // Traverse top row
        for (int j = left; j <= right; j++)
            ans.push_back(matrix[top][j]);
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                ans.push_back(matrix[bottom][j]);
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    // Input matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> result = spiralOrder(matrix);

    // Print spiral order
    for (int num : result)
        cout << num << " ";

    return 0;
}