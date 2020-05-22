#include <iostream>
using namespace std;
template <typename T>
class SinglyLinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node(T val)
        {
            data = val;
        }
    };
    Node *start;
    int size;

public:
    SinglyLinkedList()
    {
        start = NULL;
        size = 0;
    }

    // function to insert element
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
            start = temp;
            return;
        }
        if (pos == -1)
        {
            pos = size - 1;
        }
        if (pos == 0)
        {
            temp->next = start;
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
            temp->next = current->next;
            current->next = temp;
        }
    }

    // function to remove element
    T remove(int pos = -1)
    {
        if (size == 0 || pos < -1 || pos >= size)
        {
            return false;
        }
        size--;
        T temp;
        if (pos == -1)
        {
            pos = size;
        }
        if (size == 0)
        {
            temp = start->data;
            delete start;
            start = NULL;
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
            delete ref;
        }
        return temp;
    }

    //function to reverse the linked list
    void reverse()
    {
        if (size <= 1)
        {
            return;
        }
        Node *first = start;
        Node *middle = first->next;
        Node *last = middle->next;
        int count = size - 1;
        while (count--)
        {
            middle->next = first;
            first = middle;
            middle = last;
            if (last != NULL)
            {
                last = last->next;
            }
        }
        start->next = NULL;
        start = first;
    }

    // function to swap an element with the element of its previous node
    void swap(T V)
    {
        Node *current = start;
        while (current->next != NULL)
        {
            if (current->next->data == V)
            {
                current->next->data = current->data;
                current->data = V;
                return;
            }
            current = current->next;
        }
    }

    // function to print the single linked list
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
};

int main()
{
    SinglyLinkedList<int> singlylinkedlist;
    singlylinkedlist.insert(10);
    singlylinkedlist.insert(20);
    singlylinkedlist.insert(30);
    singlylinkedlist.insert(40);
    singlylinkedlist.insert(50);
    singlylinkedlist.insert(60);
    cout<<"After insertion:\n";
    singlylinkedlist.print(); 
    singlylinkedlist.remove(0);
    cout<<"After removal:\n";
    singlylinkedlist.print(); 
    singlylinkedlist.reverse();
    cout<<"After reversal:\n";
    singlylinkedlist.print(); 
    singlylinkedlist.swap(30);
    cout<<"After swapping:\n";
    singlylinkedlist.print(); 
    return 0;
}