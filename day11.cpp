// #include <iostream>
// using namespace std;

// int main()
// {
//     int m, n;
//     cin >> m >> n;

//     int first[100][100];
//     int second[100][100];

//     // Input first matrix
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> first[i][j];
//         }
//     }

//     // Input second matrix
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cin >> second[i][j];
//         }
//     }

//     // Add and print the resultant matrix
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << first[i][j] + second[i][j];

//             if (j < n - 1)
//                 cout << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }





#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    int matrix[100][100];
    int transpose[100][100];

    // Input matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Find transpose
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print transpose matrix
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << transpose[i][j];

            if (j < rows - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}