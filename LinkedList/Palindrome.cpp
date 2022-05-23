#include <iostream>
using namespace std;
#include "Node.cpp"


Node *middleNode(Node *head)
{
    Node *s = head;
    Node *f = head;
    while (f != NULL && f->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

bool compareLists(Node* head1,Node* head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    // Will reach here when one is NULL
    // and other is not
    return 0;
}

void reverse(Node *head_ref)
{
    Node *prev = NULL;
    Node *current = head_ref;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
}

bool isPalindrome(Node* head)
{
    Node *slow_ptr = head, *fast_ptr = head;
    Node *second_half, *prev_of_slow_ptr = head;

    // to handle odd size list
    Node *midnode = NULL;

    // initialize result
    bool res = true;

    // move the fast_ptr by 2 and the slow_ptr by 1
    // slow_ptr will have the middle element
    if (head != NULL && head->next != NULL)
    {

        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;

            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;

        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;

        // Reverse the second half
        reverse(second_half);

        // compare
        res = compareLists(head, second_half);

        // Construct the original list back
        reverse(second_half); // Reverse the second half again

        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}
Node* takeInput_Better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        // Node n(data); We nedd to dynamically allocate our each new node
        Node *newNode = new Node(data);
        if(head==NULL){
              head=newNode;
              tail=newNode;
        }else{
            tail->next=newNode;
            tail= tail->next;
            // OR
            // tail=newNode;
        }
        cin>>data;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    
    
    return 0;

}
