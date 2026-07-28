// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int maximum = arr[0];
//     int minimum = arr[0];

//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i] > maximum)
//             maximum = arr[i];

//         if (arr[i] < minimum)
//             minimum = arr[i];
//     }

//     cout << "Max: " << maximum << endl;
//     cout << "Min: " << minimum << endl;

//     return 0;
// }





#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(const vector<int>& nums)
{
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        if (currentSum < 0)
            currentSum = nums[i];
        else
            currentSum += nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main()
{
    int n;

    cout << "========== Maximum Subarray Sum ==========\n\n";

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " integer elements:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> nums[i];
    }

    cout << "\nCalculating the maximum subarray sum...\n";

    int answer = maxSubArray(nums);

    cout << "\nMaximum Subarray Sum = " << answer << endl;

    return 0;
}