// ############_____________________________ Reverse Linked Lists_____________________################

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
    ListNode* Reverse(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward;
        while(curr!=NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;
    }
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

int main(){
    ListNode* node=new ListNode(10);
    int n;;
    cout << "enter size of first ll ";
    cin >> n;
    cout << endl<< "enter no. for ll " << endl;
    for (int j = 0; j < n; j++)
    {
        int tmp;
        cin >> tmp;
        insertAtTail(node, tmp);
    }
    
    ListNode* ans=Reverse(node);

    while(ans->next!=NULL){
        cout<<ans->val;
        ans=ans->next;
    }
}