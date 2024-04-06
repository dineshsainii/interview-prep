#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;

        Node(int idata, Node *inext = nullptr) : data(idata), next(inext) {}
};

Node* ConvertArr2LL(std::vector<int> &arr)
{   
    //empty array
    if (arr.size() == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (size_t i = 1; i<arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty list.\n";
        return;
    }

    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data <<" ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Node* InsertHead(Node* head, int val)
// {
//     //list is empty
//     if (head == nullptr)
//     {
//         Node *newNode = new Node(val);
//         return newNode;
//     }

//     Node *newNode = new Node(val);
//     newNode->next = head;
//     head = newNode;
//     return head;
// }

void InsertHead(Node **head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

void InsertTail(Node **head, int val)
{
    Node *newNode = new Node(val);
    if (*head == nullptr)
    {
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
// void InsertAtKth(Node *&head, int k, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == nullptr || k ==1)
//     {
//         newNode->next = head;
//         head = newNode;
//         return;
//     }

//     int count = 0;
//     Node *temp = head;
//     Node *prev = nullptr;
//     while (temp)
//     {
//         count++;
//         if (count == k)
//         {
//             newNode->next = temp;
//             prev->next = newNode;
//             return;
//         }
//         prev = temp;
//         temp = temp->next;
//     }
//     if (count+1 == k)
//     {
//         prev->next = newNode;
//         return;
//     }
// }

void InsertAtKth(Node *&head, int k, int val)
{
    if (k <= 0)
    {
        std::cout << "Incorrect k value\n";
        return;
    }
        

    Node *newNode = new Node(val);
    if (head == nullptr || k == 1)
    {   
        newNode->next = head;
        head = newNode;
        return;
    }

    int count = 0;
    Node *currNode = head;
    while (count < k-2 && currNode->next)
    {
        currNode = currNode->next;
        count++;
    }

    newNode->next = currNode->next;
    currNode->next = newNode;
}

void InsertBefore(Node *&head, int befval, int val)
{
    if (head == nullptr)
    {
        std::cout << "Empty list\n";
        return;
    }

    Node *newNode = new Node(val);
    if (head->data == befval)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *currNode = head;
    while (currNode->next)
    {
        if (currNode->next->data == befval)
        {
            newNode->next = currNode->next;
            currNode->next = newNode;
            return;
        }
        currNode = currNode->next;
    }
    std::cout << "Value " << befval << " not found in the list.\n";
}

int main()
{
    std::vector<int> arr = {12, 24, 36, 418, 50};
    Node *head = ConvertArr2LL(arr);
    Print(head);
    // head = InsertHead(head, 10);
    InsertHead(&head, 10);
    Print(head);
    InsertTail(&head, 60);
    Print(head);
    InsertAtKth(head, 1, 15);
    Print(head);
    InsertBefore(head, 10, 69);
    Print(head);
    return 0;
}