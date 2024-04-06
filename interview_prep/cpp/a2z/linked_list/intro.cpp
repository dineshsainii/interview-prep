#include <iostream>
class Node
{
    //private:
    public:
        int data;
        Node* next;
    public:
        Node(int idata): data(idata), next(nullptr) {}
        Node (int idata, Node* iptr) : data(idata), next(iptr) {}
        friend std::ostream& operator<<(std::ostream& rout, Node obj);
};

std::ostream& operator<<(std::ostream& rout, Node obj)
{
    rout << obj.data<< " " << obj.next;
    return rout;
}

int main()
{
    Node* x = new Node(10);
    std::cout << *x;
    std::cout << x->data << std::endl;
    return 0;
}