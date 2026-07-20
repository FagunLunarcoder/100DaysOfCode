// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     int left = 0;
//     int right = s.length() - 1;

//     while (left < right) {
//         char temp = s[left];
//         s[left] = s[right];
//         s[right] = temp;
//         left++;
//         right--;
//     }

//     cout << s;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <string>    // Added for handling string input
#include <algorithm> // Required for std::swap

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// Updated driver code to take user input
int main() {
    Solution solution;
    string inputStr;
    
    // 1. Get the string from the user
    cout << "Enter a string to reverse: ";
    cin >> inputStr; 
    
    // 2. Convert the string into a vector of characters
    vector<char> s(inputStr.begin(), inputStr.end());
    
    // 3. Call the optimized function
    solution.reverseString(s);
    
    // 4. Print the final result
    cout << "Reversed output: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    
    return 0;
};