#include <iostream>
#include <vector>

using namespace std;

class LinkedListNode
{
public:
    int value;
    LinkedListNode *next;

    LinkedListNode(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};
LinkedListNode *merge_k_lists(vector<LinkedListNode *> &lists)
{
    // Write your code here.
    if (lists.empty())
        return NULL;
    int numOfLists = lists.size();

    LinkedListNode *mainListNode = lists[0];
    LinkedListNode *prev = NULL;

    for (int i = 1; i < numOfLists; i++)
    {
        LinkedListNode *mergingNode = lists[i];
        LinkedListNode *mainListNode = lists[0];

        while (mergingNode != NULL && mainListNode != NULL)
        {
            if (mergingNode->value <= mainListNode->value && mainListNode == lists[0])
            {
                LinkedListNode *temp = new LinkedListNode(mergingNode->value);
                temp->next = mainListNode;
                mainListNode = temp;
                lists[0] = temp;
                mergingNode = mergingNode->next;
            }
            else if ((mergingNode->value <= mainListNode->value))
            {
                prev->next = mergingNode;
                mergingNode = mergingNode->next;
                prev->next->next = mainListNode;
                mainListNode = prev->next;
            }
            else
            {
                prev = mainListNode;
                mainListNode = mainListNode->next;
            }
        }
        if (mergingNode != NULL)
        {
            prev->next = mergingNode;
        }
    }
    return lists[0];
}