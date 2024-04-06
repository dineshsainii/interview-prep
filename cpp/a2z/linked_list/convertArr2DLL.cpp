#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;
        Node *prev;

    Node(int idata) : data(idata), next(nullptr), prev(nullptr){}
    Node(int idata, Node *iprev, Node *inext) : data(idata), next(inext), prev(iprev) {}
};

Node* convertArr2DLL(std::vector<int> arr)
{
    if (arr.size()==0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i<arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void Print(Node *head)
{
    Node *temp = head;
    while(temp->next)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data;
    std::cout << std::endl;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
}
void PrintBack(Node *tail)
{
    Node *temp = tail;
    while(temp)
    {
        std::cout << temp->data <<" ";
        temp = temp->prev;
    }
}

int main()
{
    std::vector<int> arr = {12, 5, 18, 7};
    Node *head = convertArr2DLL(arr);
    Print(head);
    std::cout << std::endl;
    // PrintBack(tail);
    return 0;
}