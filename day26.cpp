// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* prev;
//     Node* next;

//     Node(int value)
//     {
//         data = value;
//         prev = nullptr;
//         next = nullptr;
//     }
// };

// int main()
// {
//     int n;
//     cin >> n;

//     Node* head = nullptr;
//     Node* tail = nullptr;

//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;

//         Node* newNode = new Node(x);

//         if (head == nullptr)
//         {
//             head = tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     Node* temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->data;
//         if (temp->next != nullptr)
//             cout << " ";
//         temp = temp->next;
//     }

//     return 0;
// }




#include <iostream>
using namespace std;

class MyLinkedList
{
    struct Node
    {
        int val;
        Node* next;
        Node(int x)
        {
            val = x;
            next = nullptr;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;

        Node* cur = head;
        while (index--)
            cur = cur->next;

        return cur->val;
    }

    void addAtHead(int val)
    {
        Node* node = new Node(val);
        node->next = head;
        head = node;
        size++;
    }

    void addAtTail(int val)
    {
        Node* node = new Node(val);

        if (!head)
            head = node;
        else
        {
            Node* cur = head;
            while (cur->next)
                cur = cur->next;
            cur->next = node;
        }

        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;

        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node* cur = head;
        for (int i = 0; i < index - 1; i++)
            cur = cur->next;

        Node* node = new Node(val);
        node->next = cur->next;
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;

        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++)
                cur = cur->next;

            Node* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }

        size--;
    }
};

int main()
{
    MyLinkedList list;

    list.addAtHead(1);
    list.addAtTail(3);
    list.addAtIndex(1, 2);

    cout << list.get(1) << endl;

    list.deleteAtIndex(1);

    cout << list.get(1) << endl;

    return 0;
}