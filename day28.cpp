// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;

//     Node(int x) {
//         data = x;
//         next = nullptr;
//     }
// };

// int main() {
//     int n;
//     cin >> n;

//     if (n <= 0) return 0;

//     Node* head = nullptr;
//     Node* tail = nullptr;

//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;

//         Node* newNode = new Node(x);

//         if (!head) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     // Make the list circular
//     tail->next = head;

//     // Traverse circular linked list
//     Node* temp = head;
//     do {
//         cout << temp->data;
//         temp = temp->next;

//         if (temp != head)
//             cout << " ";
//     } while (temp != head);

//     cout << endl;

//     return 0;
// }






#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        // Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode *prev = nullptr, *cur = slow->next;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // Compare both halves
        ListNode *p1 = head, *p2 = prev;
        while (p2) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* node = new ListNode(x);

        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    Solution obj;

    cout << (obj.isPalindrome(head) ? "true" : "false") << endl;

    return 0;
}