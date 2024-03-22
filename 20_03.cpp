
// ############_____________________________ Merge In Between Linked Lists_____________________################

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {

        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *p1 = list1;
        ListNode *p2 = list1;

        for (int i = 0; i < a - 1; i++)
        {
            p1 = p1->next;
            // temp=temp->next;
        }
        
        for (int i = 0; i < b; i++)
        {
            p2 = p2->next;
        }
        ListNode *temp = p2->next;
        p1->next = list2;
        ListNode *p3 = list2;
        while (p3->next != NULL)
        {
            p3 = p3->next;
        }
        p3->next = temp;

        return list1;
    }
};

void insertAtTail(ListNode *&head, int data)
{

    ListNode *newnode = new ListNode(data);
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

int main()
{

    vector<ListNode *> tmp;
    ListNode *node = new ListNode(10);
    ListNode *head = node;
    ListNode *node2 = new ListNode(100);
    ListNode *head2 = node2;
    tmp.push_back(head);
    tmp.push_back(head2);
    int i = 1;
    while (i != 3)
    {
        int n;

        cout << "enter size of first ll " << i << " ";
        cin >> n;
        cout << endl
             << "enter no. for ll " << endl;
        ListNode *ptr = tmp[i - 1];
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            insertAtTail(ptr, tmp);
        }

        i++;
    }
    Solution obj;
    ListNode *ans = obj.mergeInBetween(tmp[0], 3, 4, tmp[1]);
    while (ans != NULL)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }
}