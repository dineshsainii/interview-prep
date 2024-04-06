#include <iostream>
#include <vector>
#include <memory>

class Node
{
    public:
        int data;
        // Node *next;
        // Node *prev;
        std::unique_ptr<Node> next;
        Node(int idata, Node *inext = nullptr) : data(idata), next(inext) {} 
};

std::unique_ptr<Node> ConvertArr2LL(std::vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    
    std::unique_ptr<Node> head = std::make_unique<Node>(arr[0]);
    Node *prev = head.get();
    for (size_t i = 1; i < arr.size(); ++i)
    {
        prev->next = std::make_unique<Node>(arr[i]);
        prev = prev->next.get();
    }

    return head;
}

void DeleteHead(std::unique_ptr<Node>& head) {
    if (!head)
        return;
    
    head = std::move(head->next);
}
void Print(const Node *head)
{
    const Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    std::vector<int> arr = {12, 24, 36, 418, 50};
    std::unique_ptr<Node> head(ConvertArr2LL(arr));
    Print(head.get());
    std::cout << std::endl;
    DeleteHead(head);
    Print(head.get()); // After deleting head
    return 0;
}
