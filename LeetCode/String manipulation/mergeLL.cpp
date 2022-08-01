#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    ListNode *head{NULL};
    ListNode *createLists(ListNode *list1)
    {

        if (head == NULL)
            head = list1;
        else
        {
            ListNode *curr = head;
            ;
            ListNode *prev = NULL;
            while (curr != NULL)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = list1;
        }
        return head;
    }
    void printList(ListNode *list1)
    {
        if (list1 == NULL)
            cout << "List is empty" << endl;
        else
        {
            ListNode *curr = list1;
            while (curr != NULL)
            {
                cout << curr->val;
                curr = curr->next;
                if (curr != NULL)
                    cout << " -> ";
            }
            cout << endl;
        }
    }

    int calculateSize(ListNode *head)
    {
        int size{0};
        ListNode *curr = head;
        while (curr != NULL)
        {
            size++;
            curr = curr->next;
        }
        return size;
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL &&
            list2 == NULL)
            return list1;
        else if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        ListNode *head1 = list1;
        ListNode *head2 = list2;
        int size1{0}, size2{0};
        bool isHead1Large = false;

        ListNode *curr1 = head1;
        ListNode *curr2 = head2;
        ListNode *currSmallListNode;
        ListNode *currLongListNode;

        size1 = calculateSize(head1);
        size2 = calculateSize(head2);

        if (size1 <= size2)
        {
            currSmallListNode = list1;
            currLongListNode = list2;
        }
        else
        {
            currSmallListNode = list2;
            currLongListNode = list1;
            isHead1Large = true;
        }

        ListNode *prev{NULL};
        while (currSmallListNode != NULL && currLongListNode != NULL)
        {

            if (currSmallListNode->val <= currLongListNode->val)
            {
                ListNode *newNode = new ListNode(currSmallListNode->val, currLongListNode);
                currSmallListNode = currSmallListNode->next;
                currLongListNode = newNode;

                if (prev != NULL)
                {
                    prev->next = newNode;
                }
                else
                {
                    if (isHead1Large)
                        head1 = newNode;
                    else
                        head2 = newNode;
                }
            }
            else
            {
                prev = currLongListNode;
                currLongListNode = currLongListNode->next;
            }
        }

        if (currSmallListNode != NULL && currLongListNode == NULL)
        {
            prev->next = currSmallListNode;
        }

        if (isHead1Large)
            return head1;
        else
            return head2;
    }

    ListNode *middleNode(ListNode *head)
    {
        int size = calculateSize(head);
        cout <<size<<endl;
        int middle = (size / 2) + 1;
        ListNode *curr = head;
        int idx{0};

        while (curr != NULL)
        {
            idx++;
            if (idx == middle)
                return curr;
            curr = curr->next;
        }
        return head;
    }
};

int main()
{
    Solution *obj = new Solution();
    Solution *obj1 = new Solution();
    ListNode *head1 = new ListNode();
    ListNode *head2 = new ListNode();
    ListNode *merge = new ListNode();
    ListNode *middle = new ListNode();

    for (int i = -15; i < 1; i++)
    {
        ListNode *node = new ListNode(i++, NULL);
        head1 = obj->createLists(node);
    }
    for (int i = -9; i < 6; i++)
    {
        ListNode *node = new ListNode(i++, NULL);
        head2 = obj1->createLists(node);
    }
    obj->printList(head1);
    obj1->printList(head2);
    /* obj->reverseSolution();
     cout << "Reverse Solution"<<endl;
     obj->printSolution();*/
      cout <<"MERGE"<<endl;
    merge = obj->mergeTwoLists(head1, head2);
    obj->printList(merge);

    cout <<"MIDDLE"<<endl;
    middle = obj->middleNode(head1);
    obj->printList(middle);
    middle = obj->middleNode(head2);
    obj->printList(middle);
    return 0;
}
