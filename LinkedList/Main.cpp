#include <iostream>
using namespace std;
#include "Node.cpp"
#include "InsertAndDelete.cpp"
#include "Recursive.cpp"
#include "PrintList.cpp"
#include "Misc.cpp"

int main()
{
    Node* head = takeInput_Better();
    print(head);
    // deleteRec(head,2);
    removeDup(head,head,head);
    print(head);
    // printRec(head);
    return 0;
}
