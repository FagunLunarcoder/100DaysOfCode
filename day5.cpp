// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int p;
//     cin >> p;

//     vector<int> a(p);
//     for (int i = 0; i < p; i++)
//         cin >> a[i];

//     int q;
//     cin >> q;

//     vector<int> b(q);
//     for (int i = 0; i < q; i++)
//         cin >> b[i];

//     int i = 0, j = 0;

//     while (i < p && j < q) {
//         if (a[i] <= b[j])
//             cout << a[i++] << " ";
//         else
//             cout << b[j++] << " ";
//     }

//     while (i < p)
//         cout << a[i++] << " ";

//     while (j < q)
//         cout << b[j++] << " ";

//     return 0;
// }





#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> nums1(m + n);
    vector<int> nums2(n);

    // Read the first m elements of nums1
    for (int i = 0; i < m; i++)
        cin >> nums1[i];

    // The last n positions remain 0
    for (int i = m; i < m + n; i++)
        nums1[i] = 0;

    // Read nums2
    for (int i = 0; i < n; i++)
        cin >> nums2[i];

    merge(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";

    return 0;
}