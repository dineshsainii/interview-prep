#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int idata, Node *iprev = nullptr, Node *inext = nullptr)
        {
            data = idata;
            prev = iprev;
            next = inext;
        }
};

Node* ConvertArr2DLL(std::vector<int> &arr)
{
    if ( arr.size()==0 )
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *previous = head;

    for (int i = 1; i<arr.size(); i++)
    {
        Node *temp = new Node(arr[i], previous);
        previous->next = temp;
        previous = temp;
    }

    return head;
    
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List.\n";
        return; 
    }

    Node *temp = head;
    Node *previous = nullptr;
    while (temp)
    {
        previous = temp;
        std::cout << temp->data <<" ";
        temp = temp->next;
    }
    std::cout << std::endl;
    while (previous)
    {
        std::cout << previous->data <<" ";
        previous = previous->prev;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {12, 24, 36, 418, 50};
    Node* head = ConvertArr2DLL(arr);
    Print(head);

    return 0;
}