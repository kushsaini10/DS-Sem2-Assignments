#include <iostream>
using namespace std;
template <typename T>
class DoublyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next, *previous;
        Node(T val)
        {
            data = val;
        }
    };
    Node *start, *end;
    int size;

public:
    DoublyLinkedList()
    {
        start = end = NULL;
        size = 0;
    }

    // function to insert an element in doubly linked list
    void insert(T val, int pos = -1)
    {
        if (pos < -1 || pos > size)
        {
            return;
        }
        size++;
        Node *temp = new Node(val);
        if (start == NULL)
        {
            start = end = temp;
            return;
        }
        if (pos == -1)
        {
            end->next = temp;
            temp->previous = end;
            temp->next = NULL;
            end = temp;
        }
        else if (pos == 0)
        {
            temp->next = start;
            start->previous = temp;
            start = temp;
        }
        else
        {
            pos--;
            Node *current = start;
            while (pos > 0)
            {
                current = current->next;
                pos--;
            }
            current->next->previous = temp;
            current->next = temp;
            temp->next = current->next;
            temp->previous = current;
        }
    }

    // function to remove an element from doubly linked list
    T remove(int pos = -1)
    {
        if (size == 0 || pos < -1 || pos >= size)
        {
            return false;
        }
        size--;
        T temp;
        if (size == 0)
        {
            temp = start->data;
            delete start;
            start = end = NULL;
        }
        else if (pos == -1 || pos == size)
        {
            temp = end->data;
            Node *ref = end;
            end = end->previous;
            end->next = NULL;
            delete ref;
            return temp;
        }
        else if (pos == 0)
        {
            Node *ref = start;
            temp = start->data;
            start = start->next;
            delete ref;
        }
        else
        {
            pos--;
            Node *current = start;
            while (pos > 0)
            {
                current = current->next;
                pos--;
            }
            Node *ref = current->next;
            temp = current->next->data;
            current->next = current->next->next;
            if (current->next->next != NULL)
            {
                current->next->next->previous = current;
            }
            delete ref;
        }
        return temp;
    }

    // function to reverse doubly linked list

    void reverse()
    {
        if (size <= 1)
        {
            return;
        }
        Node *first = start;
        Node *last = end;
        for (int i = 0; i < size / 2; i++)
        {
            T temp = first->data;
            first->data = last->data;
            last->data = temp;
            first = first->next;
            last = last->previous;
        }
    }

    //function to print the doubly linked list
    void print()
    {
        Node *current = start;
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
    void printend()
    {
        cout << end->data << "\n";
    }
};

int main()
{
    DoublyLinkedList<int> doublylinkedlist;
    doublylinkedlist.insert(10);
    doublylinkedlist.insert(20);
    doublylinkedlist.insert(30);
    doublylinkedlist.insert(40);
    doublylinkedlist.insert(50);
    doublylinkedlist.insert(60);
    cout<<"After insertion\n";
    doublylinkedlist.print(); 
    doublylinkedlist.remove();
    cout<<"After removal\n";
    doublylinkedlist.print(); 
    doublylinkedlist.reverse();
    cout<<"After reverse:\n";
    doublylinkedlist.print(); 
    return 0;
}