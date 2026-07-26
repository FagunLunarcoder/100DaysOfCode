// #include <iostream>
// using namespace std;

// int main()
// {
//     int rows, cols;
//     cin >> rows >> cols;

//     int value;
//     int diagonalSum = 0;

//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             cin >> value;

//             // Add only the primary diagonal elements
//             if (i == j)
//             {
//                 diagonalSum += value;
//             }
//         }
//     }

//     cout << diagonalSum;

//     return 0;
// }




#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if first row contains any zero
    for (int j = 0; j < cols; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if first column contains any zero
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Use first row and first column as markers
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set elements to zero based on row markers
    for (int i = 1; i < rows; i++)
    {
        if (matrix[i][0] == 0)
        {
            for (int j = 1; j < cols; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set elements to zero based on column markers
    for (int j = 1; j < cols; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 1; i < rows; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero the first row if needed
    if (firstRowZero)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Zero the first column if needed
    if (firstColZero)
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}