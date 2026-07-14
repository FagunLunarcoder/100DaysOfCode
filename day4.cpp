// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);

//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int left = 0, right = n - 1;

//     while (left < right) {
//         swap(arr[left], arr[right]);
//         left++;
//         right--;
//     }

//     for (int i = 0; i < n; i++) {
//         cout << arr[i];
//         if (i != n - 1) cout << " ";
//     }

//     return 0;
// }






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                n--;
            } else {
                i++;
            }
        }

        return n;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int val;
    cin >> val;

    Solution obj;
    int k = obj.removeElement(nums, val);

    cout << k << endl;

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}