#include <iostream>

class Node
{
    public:
        int val;
        Node* next;

        Node(int data) : val(data), next(nullptr) {}
        Node(int data, Node* node) : val(data), next(node) {}
};

void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void InsertAtHead(Node **head, int val)
{
    Node *temp = new Node(val);
    temp->next = *head;
    *head = temp;
}

void InsertAtTail(Node **head, int data)
{
    Node *newNode = new Node(data);
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

void InsertAtK(Node **head, int val, int k)
{
    Node *newNode = new Node(val);
    if (*head == nullptr)
    {
        if (k == 1)
        {
            *head = newNode;
            return;
        }
        else{
            delete newNode;
            std::cout << "Invalid k for empty LL.\n";
            return;
        }
    }
    if (k==1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    int count = 0;
    Node *temp = *head;
    while (temp)
    {
        count++;
        
        if (count == k-1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    if (count < k)
    {
        std::cout << "Invalid K \n";
    }
}

void InsertBeforeVal(Node **head, int data, int val)
{
    //if head is nullptr then given val can't be valid. 
    if (*head == nullptr)
    {
        return;
    }

    //if given val is at first node
    if ((*head)->val == val)
    {
        Node *newNode = new Node(data, *head);
        *head = newNode;
        return;
    }

    Node *temp = *head;
    while (temp->next)
    {
        if (temp->next->val == val)
        {
            Node *newNode = new Node(data, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
}



int main()
{   
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    std::cout << "Original LL. \n";
    Print(head);
    InsertAtHead(&head, 1);
    std::cout << "After Inserting 1 in original LL.\n";
    Print(head);
    Node *nhead = nullptr;
    InsertAtHead(&nhead, 1);
    std::cout << "After inserting 1 in empty LL. \n";
    Print(nhead);
    InsertAtTail(&head, 50);
    std::cout << "After inserting 50 at tail of original LL. \n";
    Print(head);
    nhead = nullptr;
    InsertAtTail(&nhead, 50);
    std::cout << "After inserting 50 at tail of an empty LL. \n";
    Print(nhead);
    InsertAtK(&head, 5, 2);
    std::cout << "After inserting 5 at k = 2 in given LL. \n";
    Print(head);
    nhead = nullptr;
    InsertAtK(&nhead, 10, 1);
    std::cout << "After inserting 10 at k = 1 in empty LL. \n";
    Print(nhead);
    InsertAtK(&head, 7, 1);
    std::cout << "After inserting 7 at k=1 in given LL. \n" ;
    Print(head);    
    InsertBeforeVal(&head, 100, 50);
    Print(head);
    return 0;
}