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

// // Function to insert a node at the end
// void insert(Node*& head, int value)
// {
//     Node* newNode = new Node(value);

//     if (head == nullptr)
//     {
//         head = newNode;
//         return;
//     }

//     Node* temp = head;

//     while (temp->next != nullptr)
//         temp = temp->next;

//     temp->next = newNode;
// }

// // Function to count the number of nodes
// int countNodes(Node* head)
// {
//     int count = 0;

//     while (head != nullptr)
//     {
//         count++;
//         head = head->next;
//     }

//     return count;
// }

// int main()
// {
//     int n;

//     cout << "=====================================\n";
//     cout << "     Count Nodes in Linked List\n";
//     cout << "=====================================\n\n";

//     cout << "Enter the number of nodes: ";
//     cin >> n;

//     Node* head = nullptr;

//     cout << "Enter " << n << " elements: ";

//     for (int i = 0; i < n; i++)
//     {
//         int value;
//         cin >> value;
//         insert(head, value);
//     }

//     cout << "\nTotal number of nodes in the linked list: "
//          << countNodes(head) << endl;

//     return 0;
// }



#include <iostream>
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

// Insert a node at the end of the linked list
void insert(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

// Reverse the linked list
Node* reverseList(Node* head)
{
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Display the linked list
void display(Node* head)
{
    if (head == nullptr)
    {
        cout << "The linked list is empty.";
        return;
    }

    while (head != nullptr)
    {
        cout << head->data;

        if (head->next != nullptr)
            cout << " -> ";

        head = head->next;
    }
}

int main()
{
    int n;

    cout << "=====================================\n";
    cout << "      Reverse Linked List Program\n";
    cout << "=====================================\n\n";

    cout << "Enter the number of nodes: ";
    cin >> n;

    Node* head = nullptr;

    if (n > 0)
    {
        cout << "Enter " << n << " elements: ";

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            insert(head, value);
        }
    }

    cout << "\nOriginal Linked List:\n";
    display(head);

    head = reverseList(head);

    cout << "\n\nReversed Linked List:\n";
    display(head);

    cout << endl;

    return 0;
}