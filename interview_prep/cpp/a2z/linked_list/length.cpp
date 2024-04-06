#include <iostream>
#include <vector>

struct Node
{
    int data;
    Node* next;
    
    Node(int idata) : data(idata), next(nullptr) {}

};

Node* ConvertArr2LL(std::vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i<arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int LengthOfLL(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";

}

int main()
{
    std::vector<int> arr = {2,3,4,5,6,7,8};

    Node *node  = ConvertArr2LL(arr);
    Print(node);
    std::cout << "Length: " << LengthOfLL(node);
    return 0;
}