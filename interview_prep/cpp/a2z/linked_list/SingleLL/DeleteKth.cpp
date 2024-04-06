#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;

        Node(int idata = 0, Node* inext = nullptr) : data(idata), next(inext) {}
};

Node* ConvertArr2LL(std::vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i<arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* DeleteK(Node *head, int k)
{
    //Empty list
    if (head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
        return nullptr;
    }

    Node *temp = head;
    //K==1, deleting head
    if (k == 1)
    {
        head = head->next;
        delete temp;
        return head;
    }

    int count = 0; Node *prev = nullptr;
    while(temp)
    {
        count++;
        if (k == count)
        {  
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}   

int main()
{
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    Node *head = ConvertArr2LL(arr);
    Print(head);
    head = DeleteK(head, 1);
    Print(head);
    head = DeleteK(head, 7);
    Print(head);
}