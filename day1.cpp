//  #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;


//     int arr[n + 1];

//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

//     int pos, x;
//     cin >> pos;
//     cin >> x;

//     for (int i = n; i >= pos; i--)
//         arr[i] = arr[i - 1];

    
//     arr[pos - 1] = x;

    
//     for (int i = 0; i <= n; i++) {
//         cout << arr[i];
//         if (i != n) cout << " ";
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target: ";
    cin >> target;

    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    if (!ans.empty()) {
        cout << "Indices are: " << ans[0] << " " << ans[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}