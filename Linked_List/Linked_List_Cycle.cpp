#include <iostream>
using namespace std;

// -------------------------
// Definition of ListNode
// -------------------------
struct ListNode
{
    int val;
    ListNode *next;

    // Constructor
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

// ----------------------------------------------------------
// Function to detect cycle in a linked list
// Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
// ----------------------------------------------------------
bool LinkedList_cycle(ListNode *head)
{
    ListNode *slow = head; // moves 1 step
    ListNode *fast = head; // moves 2 steps

    // Traverse while fast pointer and its next are valid
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;           // move slow pointer
        fast = fast->next->next;     // move fast pointer

        if (slow == fast)            // if both meet → cycle
            return true;
    }

    return false; // fast reached end → no cycle
}

// ----------------------------------------------------------
// Helper function to print list (only if no cycle)
// ----------------------------------------------------------
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// ----------------------------------------------------------
// Main Function
// ----------------------------------------------------------
int main()
{
    // Creating nodes manually
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // --------------------------------------
    // Create cycle:
    // Last node (5) points to node (3)
    // --------------------------------------
    head->next->next->next->next->next = head->next->next;
    //                  5 -> 3 (cycle here)

    // --------------------------------------
    // Detect cycle
    // --------------------------------------
    if (LinkedList_cycle(head))
        cout << "Cycle detected in Linked List!" << endl;
    else
        cout << "No cycle in Linked List." << endl;

    return 0;
}
