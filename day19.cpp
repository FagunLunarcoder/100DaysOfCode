// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <cstdlib>

// using namespace std;

// int main()
// {
//     int n;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     if (n < 2)
//     {
//         cout << "At least two elements are required." << endl;
//         return 0;
//     }

//     vector<int> arr(n);

//     cout << "Enter " << n << " integers: ";
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     // Sort the array
//     sort(arr.begin(), arr.end());

//     int left = 0;
//     int right = n - 1;

//     int first = arr[left];
//     int second = arr[right];
//     int minSum = INT_MAX;

//     while (left < right)
//     {
//         int currentSum = arr[left] + arr[right];

//         if (abs(currentSum) < abs(minSum))
//         {
//             minSum = currentSum;
//             first = arr[left];
//             second = arr[right];
//         }

//         if (currentSum < 0)
//             left++;
//         else if (currentSum > 0)
//             right--;
//         else
//             break; // Perfect answer (sum = 0)
//     }

//     cout << "\nPair whose sum is closest to zero: "
//          << first << " " << second << endl;

//     cout << "Their sum = " << first + second << endl;

//     return 0;
// }






#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int totalSum = nums[0];

    int maxEnding = nums[0];
    int maxSum = nums[0];

    int minEnding = nums[0];
    int minSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        totalSum += nums[i];

        // Kadane's Algorithm for maximum subarray sum
        maxEnding = max(nums[i], maxEnding + nums[i]);
        maxSum = max(maxSum, maxEnding);

        // Kadane's Algorithm for minimum subarray sum
        minEnding = min(nums[i], minEnding + nums[i]);
        minSum = min(minSum, minEnding);
    }

    // If all elements are negative
    if (maxSum < 0)
    {
        cout << "\nMaximum Circular Subarray Sum = " << maxSum << endl;
    }
    else
    {
        cout << "\nMaximum Circular Subarray Sum = "
             << max(maxSum, totalSum - minSum) << endl;
    }

    return 0;
}