#include <iostream>
using namespace std;
template <typename T>
class CircularLinkedList
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
    Node *start, *end;
    int size;

public:
    CircularLinkedList()
    {
        start = NULL;
        size = 0;
    }
    T front()
    {
        if (size == 0)
        {
            return false;
        }
        return start->data;
    }
    T back()
    {
        if (size == 0)
        {
            return false;
        }
        return end->data;
    }
    void advance()
    {
        if (size == 0)
        {
            return;
        }
        start = start->next;
        end = end->next;
    }

    //to insert element in the circular linked list
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
            start->next = end;
            end->next = start;
            return;
        }
        if (pos == -1)
        {
            end->next = temp;
            end = temp;
            end->next = start;
            return;
        }
        if (pos == 0)
        {
            temp->next = start;
            start = temp;
            end->next = temp;
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
    // function to remove element from the circular linked list
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
            start = end = NULL;
        }
        else if (pos == 0)
        {
            Node *ref = start;
            temp = start->data;
            end->next = start = start->next;
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
            if (ref == end)
            {
                end = current;
            }
            temp = current->next->data;
            current->next = current->next->next;
            delete ref;
        }
        return temp;
    }
    //function to print circular linked list
    void print()
    {
        Node *current = start;
        int count = 2 * size;
        while (count--)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "START\n";
    }
};

int main()
{
    CircularLinkedList<int> circularLinkedList;
    circularLinkedList.insert(10);
    circularLinkedList.insert(20);
    circularLinkedList.insert(30);
    circularLinkedList.insert(40);
    circularLinkedList.insert(50);
    circularLinkedList.insert(60);
    cout<<"After insetion: "<<endl;
    circularLinkedList.print(); 
    cout<<"After remove :";
    circularLinkedList.remove();
    circularLinkedList.print();                 
    cout << "Front of the circularLinkedList: "<<circularLinkedList.front() << "\n"; 
    cout << "Back of the circularLinkedList :"<< circularLinkedList.back() << "\n";  
    circularLinkedList.advance();
    cout<<"After advance function:"<<endl;
    circularLinkedList.print();                
    cout << "Front of the circularLinkedList: "<<circularLinkedList.front() << "\n"; 
    cout << "Back of the circularLinkedList :"<< circularLinkedList.back() << "\n";  
    return 0;
}