#include <iostream>

template<typename T>
class Node
{
    public:
        T data;
        Node<T>* next;

    public:
        // Node()
        // {
        //     data = 0;
        //     next = nullptr;
        // }
        Node(int idata = 0, Node<int>* nptr = nullptr): data(idata), next(nptr) {}

};
template<typename T>
void Print(T node)
{
    while (node!=nullptr)
    {
        std::cout << node->data << std::endl;
        node = node->next;
    }
}

int main()
{
    Node<int>* node = new Node<int>();
    Node<int>* first = new Node<int>(10, node);
    Node<int>* second = new Node<int>(20, first);
    Node<int>* third = new Node<int>(30, second);
    Node<int>* fourth = new Node<int>(40, third);
    Print<Node<int>*>(fourth);
    return 0;
}