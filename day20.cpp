// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main()
// {
//     int n;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter " << n << " integers:\n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     unordered_map<long long, long long> prefixCount;

//     long long prefixSum = 0;
//     long long zeroSumSubarrays = 0;

//     // Prefix sum 0 exists once before starting
//     prefixCount[0] = 1;

//     for (int num : arr)
//     {
//         prefixSum += num;

//         // If this prefix sum has appeared before,
//         // all previous occurrences form zero-sum subarrays.
//         if (prefixCount.find(prefixSum) != prefixCount.end())
//         {
//             zeroSumSubarrays += prefixCount[prefixSum];
//         }

//         prefixCount[prefixSum]++;
//     }

//     cout << "\nNumber of subarrays having sum equal to zero = "
//          << zeroSumSubarrays << endl;

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

    if (n < 3)
    {
        cout << "At least 3 elements are required.\n";
        return 0;
    }

    vector<int> nums(n);

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({ nums[i], nums[left], nums[right] });

                left++;
                right--;

                // Skip duplicate second elements
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicate third elements
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    if (result.empty())
    {
        cout << "\nNo triplets found whose sum is 0.\n";
    }
    else
    {
        cout << "\nTriplets whose sum is 0:\n";

        for (const auto& triplet : result)
        {
            cout << "[ "
                 << triplet[0] << ", "
                 << triplet[1] << ", "
                 << triplet[2] << " ]\n";
        }
    }

    return 0;
}