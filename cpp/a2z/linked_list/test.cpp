#include <iostream>
#include <vector>
#include <memory>

class Node
{
    public:
        int data;
        Node *next;
        // Node *prev;
        Node(int idata, Node *inext = nullptr) : data(idata), next(inext) {} 
};

Node* ConvertArr2LL(std::vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;

    Node* head = new Node(arr[0]);
    Node *prev = head;
    int size = arr.size();
    for (int i = 1; i<size; i++)
    {   
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;

}

int Length(const Node *head)
{
    int count = 0;
    const Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Print(const Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty list." << std::endl;
        return;
    }
    const Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

bool checkIfPresent(const Node *head, int val)
{
    const Node *temp = head;
    while(temp)
    {
        if (temp->data == val)
            return true;

        temp = temp->next;
    }
    return false;
}

void DeleteHead(Node* &head)
{
    if (head == nullptr)
        return;
    
    Node *temp = head;
    head = head->next;
    delete temp;
}

Node* DeleteTail(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    Node *prev = nullptr;
    while (temp->next)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    delete temp;
    return head;
    
}
//You need to give the position.
Node* DeleteKthElem(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    int length = Length(head);
    std::cout << "Length is " << length << std::endl;
    if (k>length)
    {
        std::cout << "Invalid K \n";
        return head;
    }
    if (k == 1)
    {
        std::cout << "Entered K = 1\n";
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int count  = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            temp->next = nullptr;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* DeleteByVal(Node *head, int val)
{
    if (head == nullptr)
        return nullptr;
    
    Node *temp = head;
    Node *prev = nullptr;
    if (head->data == val)
    {
        head = head->next;
        delete temp;
        return head;
    }

    while (temp)
    {
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    std::vector<int> arr = {12, 24, 36, 418, 50};
    Node* head = ConvertArr2LL(arr);
    Print(head);
    // std::cout << Length(head);
    // std::cout << std::endl;
    // int val = 418;
    // checkIfPresent(head, val) ? std::cout << "Yes" << std::endl: std::cout << "No" << std::endl;
    // DeleteHead(head);
    // Print(head);
    // DeleteTail(head);
    // Print(head);
    // head = DeleteKthElem(head, 3);
    // Print(head);
    head = DeleteByVal(head, 12);
    Print(head);

    return 0;
}