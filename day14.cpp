// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> matrix(n, vector<int>(n));

//     // Input matrix
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> matrix[i][j];
//         }
//     }

//     bool isIdentity = true;

//     // Check identity matrix
//     for (int i = 0; i < n && isIdentity; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i == j)
//             {
//                 if (matrix[i][j] != 1)
//                 {
//                     isIdentity = false;
//                     break;
//                 }
//             }
//             else
//             {
//                 if (matrix[i][j] != 0)
//                 {
//                     isIdentity = false;
//                     break;
//                 }
//             }
//         }
//     }

//     if (isIdentity)
//         cout << "Identity Matrix";
//     else
//         cout << "Not an Identity Matrix";

//     return 0;
// }







#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate(vector<vector<int>>& matrix)
{
    int n = matrix.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    rotate(matrix);

    cout << "Rotated Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}