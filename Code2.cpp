#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *insertTail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

Node *merge(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *head = NULL;
    if (head1->data > head2->data)
    {
        head = head1;
    }
    else
    {
        head = head2;
    }
    Node *temp = head;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Node *head1 = NULL;
        for (int j = 0; j < x; j++)
        {
            int data;
            cin >> data;
            head1 = insertTail(head1, data);
        }
        int y;
        cin >> y;
        Node *head2 = NULL;
        for (int j = 0; j < y; j++)
        {
            int dat;
            cin >> dat;
            head2 = insertTail(head2, dat);
        }
        print(head1);
        print(head2);
        Node *head = merge(head1, head2);
        print(head);
    }
    return 0;
}
