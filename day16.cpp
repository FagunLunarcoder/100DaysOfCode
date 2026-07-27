// #include <iostream>
// #include <vector>
// #include <unordered_map>

// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     unordered_map<int, int> freq;
//     vector<int> order;

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];

//         if (freq[arr[i]] == 0)
//             order.push_back(arr[i]);

//         freq[arr[i]]++;
//     }

//     for (int x : order)
//         cout << x << ":" << freq[x] << " ";

//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if (n == 0)
            return;

        k %= n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int k;
    cin >> k;

    Solution obj;
    obj.rotate(nums, k);

    for (int x : nums)
        cout << x << " ";

    return 0;
}