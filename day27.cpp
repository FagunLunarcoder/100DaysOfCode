// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* next;

//     Node(int val)
//     {
//         data = val;
//         next = nullptr;
//     }
// };

// Node* createList(int n)
// {
//     Node *head = nullptr, *tail = nullptr;

//     while (n--)
//     {
//         int x;
//         cin >> x;

//         Node* newNode = new Node(x);

//         if (head == nullptr)
//             head = tail = newNode;
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }
//     return head;
// }

// int getLength(Node* head)
// {
//     int len = 0;

//     while (head)
//     {
//         len++;
//         head = head->next;
//     }

//     return len;
// }

// int main()
// {
//     int n, m;

//     cout << "Enter number of nodes in the first linked list: ";
//     cin >> n;

//     cout << "Enter the elements of the first linked list: ";
//     Node* head1 = createList(n);

//     cout << "Enter number of nodes in the second linked list: ";
//     cin >> m;

//     cout << "Enter the elements of the second linked list: ";
//     Node* head2 = createList(m);

//     int len1 = getLength(head1);
//     int len2 = getLength(head2);

//     Node *p1 = head1, *p2 = head2;

//     while (len1 > len2)
//     {
//         p1 = p1->next;
//         len1--;
//     }

//     while (len2 > len1)
//     {
//         p2 = p2->next;
//         len2--;
//     }

//     while (p1 && p2)
//     {
//         if (p1->data == p2->data)
//         {
//             cout << "\nIntersection Point: " << p1->data;
//             return 0;
//         }

//         p1 = p1->next;
//         p2 = p2->next;
//     }

//     cout << "\nNo Intersection";

//     return 0;
// }




#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

Node* createList(int n)
{
    Node *head = nullptr, *tail = nullptr;

    cout << "Enter the elements of the linked list: ";

    while (n--)
    {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void createLoop(Node* head, int pos)
{
    if (pos == 0)
        return;

    Node *loopNode = nullptr, *temp = head;
    int count = 1;

    while (temp->next)
    {
        if (count == pos)
            loopNode = temp;

        temp = temp->next;
        count++;
    }

    if (count == pos)
        loopNode = temp;

    temp->next = loopNode;
}

void removeLoop(Node* head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            slow = head;

            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }

            fast->next = nullptr;
            return;
        }
    }
}

bool hasLoop(Node* head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

void display(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = createList(n);

    cout << "Enter loop starting position (0 for no loop): ";
    cin >> pos;

    createLoop(head, pos);

    removeLoop(head);

    cout << "\nLoop Removed Successfully." << endl;

    if (hasLoop(head))
        cout << "Loop Status: Loop still exists." << endl;
    else
        cout << "Loop Status: No Loop Found." << endl;

    cout << "Linked List after removing loop: ";
    display(head);

    return 0;
}