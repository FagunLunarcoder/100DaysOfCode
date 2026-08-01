// #include <iostream>
// using namespace std;

// // Node structure
// struct Node
// {
//     int data;
//     Node* next;

//     Node(int value)
//     {
//         data = value;
//         next = nullptr;
//     }
// };

// int main()
// {
//     int n;

//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     if (n <= 0)
//     {
//         cout << "Linked List is empty.";
//         return 0;
//     }

//     Node* head = nullptr;
//     Node* tail = nullptr;

//     cout << "Enter " << n << " elements: ";

//     for (int i = 0; i < n; i++)
//     {
//         int value;
//         cin >> value;

//         Node* newNode = new Node(value);

//         if (head == nullptr)
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     cout << "\nLinked List: ";

//     Node* current = head;

//     while (current != nullptr)
//     {
//         cout << current->data;

//         if (current->next != nullptr)
//             cout << " ";

//         current = current->next;
//     }

//     // Free allocated memory
//     current = head;
//     while (current != nullptr)
//     {
//         Node* temp = current;
//         current = current->next;
//         delete temp;
//     }

//     return 0;
// }




#include <iostream>
using namespace std;

// Definition of a node
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

// Function to find the middle node
ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    int n;

    cout << "Enter the number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "The linked list is empty.";
        return 0;
    }

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    cout << "Enter " << n << " node values: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    ListNode* middle = middleNode(head);

    cout << "\nMiddle node onwards: ";

    while (middle != nullptr)
    {
        cout << middle->val;

        if (middle->next != nullptr)
            cout << " ";

        middle = middle->next;
    }

    // Free memory
    while (head != nullptr)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}