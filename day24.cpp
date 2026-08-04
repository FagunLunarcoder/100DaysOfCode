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

// void deleteFirstOccurrence(Node*& head, int key)
// {
//     if (head == nullptr)
//         return;

//     if (head->data == key)
//     {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }

//     Node* prev = head;
//     Node* curr = head->next;

//     while (curr != nullptr)
//     {
//         if (curr->data == key)
//         {
//             prev->next = curr->next;
//             delete curr;
//             return;
//         }

//         prev = curr;
//         curr = curr->next;
//     }
// }

// void display(Node* head)
// {
//     while (head != nullptr)
//     {
//         cout << head->data;
//         if (head->next != nullptr)
//             cout << " ";
//         head = head->next;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     Node* head = nullptr;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         insert(head, x);
//     }

//     int key;
//     cin >> key;

//     deleteFirstOccurrence(head, key);

//     display(head);

//     return 0;
// }



#include <iostream>
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

Node* removeElements(Node* head, int val)
{
    while (head != nullptr && head->data == val)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;

    while (curr != nullptr && curr->next != nullptr)
    {
        if (curr->next->data == val)
        {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

void display(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next != nullptr)
            cout << " ";
        head = head->next;
    }
}

int main()
{
    int n;
    cin >> n;

    Node* head = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(head, x);
    }

    int val;
    cin >> val;

    head = removeElements(head, val);

    display(head);

    return 0;
}