// #include <iostream>
// using namespace std;

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

// int countOccurrences(Node* head, int key)
// {
//     int count = 0;

//     while (head != nullptr)
//     {
//         if (head->data == key)
//             count++;

//         head = head->next;
//     }

//     return count;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     Node* head = nullptr;
//     Node* tail = nullptr;

//     for (int i = 0; i < n; i++)
//     {
//         int value;
//         cin >> value;

//         Node* newNode = new Node(value);

//         if (head == nullptr)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     int key;
//     cin >> key;

//     cout << countOccurrences(head, key);

//     while (head != nullptr)
//     {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//     }

//     return 0;
// }



#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

// Returns the node where the cycle begins, or nullptr if there is no cycle.
Node* detectCycle(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return nullptr;
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "No cycle";
        return 0;
    }

    vector<Node*> nodes;

    cout << "Enter " << n << " node values: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        nodes.push_back(new Node(value));

        if (i > 0)
            nodes[i - 1]->next = nodes[i];
    }

    int pos;
    cout << "Enter cycle position (-1 for no cycle): ";
    cin >> pos;

    if (pos >= 0 && pos < n)
        nodes[n - 1]->next = nodes[pos];

    Node* result = detectCycle(nodes[0]);

    if (result != nullptr)
        cout << "Cycle starts at node with value: " << result->data;
    else
        cout << "No cycle";

    return 0;
}