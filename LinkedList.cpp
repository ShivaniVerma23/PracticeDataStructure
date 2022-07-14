#include <iostream>

using namespace std;

struct Node
{
    int data{0};
    Node *next{NULL};
};

class List
{
    Node *Head = NULL;

public:
    void addNode(int d)
    {
        Node *node = new Node();
        node->data = d;
        node->next = NULL;
        if (Head == NULL)
            Head = node;
        else
        {
            Node *curr = Head;
            Node *prev = NULL;
            while (curr != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = node;
        }
    }
    void printList()
    {
        if (Head == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *curr = Head;
            while (curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << endl;
        }
    }
    void reverseList()
    {
        if (Head == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *curr = Head;
            Node *prev{NULL};
            Node *Next{NULL};
            while (curr != NULL)
            {
                Next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = Next;
            }
            Head = prev;
        }
    }
    List *mergeSortedList(List *list1, List *list2)
    {
       if (list1->Head == NULL &&
            list2->Head == NULL)
            return list1;
        else if (list1->Head == NULL)
            return list2;
        else if (list2->Head == NULL)
            return list1;

        int size1{0}, size2{0};
        Node *head1 = list1->Head;
        Node *head2 = list1->Head;
        Node *curr1 = head1;
        Node *curr2 = head2;
        List *smallList;
        List *longList;
        Node *mergeNode = NULL;
        while (curr1 != NULL)
        {
            size1++;
            curr1 = curr1->next;
        }
        while (curr2 != NULL)
        {
            size2++;
            curr2 = curr2->next;
        }

        if (size1 <= size2)
        {
            smallList = list1;
            longList = list2;
        }
        else
        {
            smallList = list2;
            longList = list1;
        }

        curr1 = smallList->Head;
        curr2 = longList->Head;
        Node *prev{NULL};

        while (curr1 != NULL && curr2 != NULL)
        {

            if (curr1->data <= curr2->data)
            {
                Node *add = new Node();
                add->data = curr1->data;
                add->next = curr2;
                if (curr2 == longList->Head)
                    longList->Head = add;
                else
                     prev->next = add;
                curr1 = curr1->next;
                curr2 = add;
                
            }
            else
            {
            prev = curr2;
            curr2 = curr2->next;
            }
        }
        if (curr1 != NULL)
        {
            prev->next = curr1;
        }
        return longList;

    }
};

int main()
{
    List *obj = new List();
    List *obj1 = new List();
    List *merge = new List();
    for (int i = -15; i < 1; i++)
        obj->addNode(i+2);
    for (int i = -10; i < 2; i++)
        obj1->addNode(i+3);
    obj->printList();
    obj1->printList();
    /* obj->reverseList();
     cout << "Reverse List"<<endl;
     obj->printList();*/
    merge = obj1->mergeSortedList(obj, obj1);
    merge->printList();
    return 0;
}