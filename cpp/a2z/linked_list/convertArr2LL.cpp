#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;

    public:
        Node(int idata) : data(idata), next(nullptr) {}
        Node(int idata, Node* iptr) : data(idata), next(iptr) {}  
};

Node* convertArr2LL(std::vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
    
}

void print(Node* head)
{
    Node *temp = head;
    while(temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    std::vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2LL(arr);

    print(head);
    
    return 0;
}
