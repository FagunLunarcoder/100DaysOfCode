// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main()
// {
//     int n;

//     cout << "Enter the number of elements: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter " << n << " elements: ";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int k;
//     cout << "Enter the number of right rotations: ";
//     cin >> k;

//     if (n == 0)
//         return 0;

//     k %= n;

//     reverse(arr.begin(), arr.end());
//     reverse(arr.begin(), arr.begin() + k);
//     reverse(arr.begin() + k, arr.end());

//     cout << "\nArray after rotating to the right by " << k << " position(s):\n";

//     for (int num : arr)
//     {
//         cout << num << " ";
//     }

//     cout << endl;

//     return 0;
// }





#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> answer(n, 1);

    // Store prefix products
    int prefixProduct = 1;
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefixProduct;
        prefixProduct *= nums[i];
    }

    // Multiply with suffix products
    int suffixProduct = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= suffixProduct;
        suffixProduct *= nums[i];
    }

    cout << "\nProduct of array except self:\n";

    for (int value : answer)
    {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}