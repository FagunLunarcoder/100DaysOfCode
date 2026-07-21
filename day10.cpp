// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     int i = 0, j = s.size() - 1;

//     while (i < j) {
//         if (s[i] != s[j]) {
//             cout << "NO";
//             return 0;
//         }
//         i++;
//         j--;
//     }

//     cout << "YES";
//     return 0;
// }


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
{
    // Store the smaller array in the hash map
    if (nums1.size() > nums2.size())
        swap(nums1, nums2);

    unordered_map<int, int> freq;

    // Count frequency of elements in the smaller array
    for (int num : nums1)
        freq[num]++;

    vector<int> result;

    // Find intersection
    for (int num : nums2)
    {
        if (freq[num] > 0)
        {
            result.push_back(num);
            freq[num]--;
        }
    }

    return result;
}

int main()
{
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    vector<int> nums1(n1);

    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++)
        cin >> nums1[i];

    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> nums2(n2);

    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++)
        cin >> nums2[i];

    vector<int> ans = intersect(nums1, nums2);

    cout << "Intersection: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}