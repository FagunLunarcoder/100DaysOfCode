// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
//     Node(int value) : data(value), next(nullptr) {}
// };

// void insert(Node*& head, Node*& tail, int value) {
//     Node* newNode = new Node(value);
//     if (head == nullptr) {
//         head = tail = newNode;
//     } else {
//         tail->next = newNode;
//         tail = newNode;
//     }
// }

// Node* mergeLists(Node* first, Node* second) {
//     Node dummy(0);
//     Node* tail = &dummy;

//     while (first != nullptr && second != nullptr) {
//         if (first->data <= second->data) {
//             tail->next = first;
//             first = first->next;
//         } else {
//             tail->next = second;
//             second = second->next;
//         }
//         tail = tail->next;
//     }
//     tail->next = (first != nullptr) ? first : second;

//     return dummy.next;
// }

// void display(Node* head) {
//     while (head != nullptr) {
//         cout << head->data;
//         if (head->next != nullptr) cout << " ";
//         head = head->next;
//     }
//     cout << endl;
// }

// void deleteList(Node* head) {
//     while (head != nullptr) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, value;
//     Node *head1 = nullptr, *tail1 = nullptr;
//     Node *head2 = nullptr, *tail2 = nullptr;

//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> value;
//         insert(head1, tail1, value);
//     }

//     cin >> m;
//     for (int i = 0; i < m; i++) {
//         cin >> value;
//         insert(head2, tail2, value);
//     }

//     Node* merged = mergeLists(head1, head2);
//     display(merged);
//     deleteList(merged);

//     return 0;
// }





#include <iostream>
#include <vector>
using namespace std;

// Node structure
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

// Insert node at the end
void insert(Node*& head, Node*& tail, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Create a cycle if position is valid
void createCycle(Node* head, Node* tail, int pos)
{
    if (pos == -1)
        return;

    Node* temp = head;

    for (int i = 0; i < pos; i++)
        temp = temp->next;

    tail->next = temp;
}

// Floyd's Cycle Detection Algorithm
bool hasCycle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node *head = nullptr, *tail = nullptr;

    cout << "Enter " << n << " node values:\n";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insert(head, tail, value);
    }

    int pos;
    cout << "Enter position to create cycle (-1 for no cycle): ";
    cin >> pos;

    createCycle(head, tail, pos);

    if (hasCycle(head))
        cout << "\nCycle Detected.\n";
    else
        cout << "\nNo Cycle Found.\n";

    return 0;
}