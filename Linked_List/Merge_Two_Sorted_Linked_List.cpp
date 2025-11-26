#include<iostream>
#include<vector>
using namespace std;

/*
 Merge two sorted singly-linked lists and return the head of the merged list.
 Approach: iterative merge using a dummy head node.
 Time: O(n + m) where n,m = lengths of the two lists.
 Space: O(1) extra (reuses existing nodes).
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // Dummy node simplifies edge cases
    ListNode dummy(0);
    ListNode *tail = &dummy;

    // Merge by always attaching the smaller current node
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part (only one of list1/list2 is non-null)
    tail->next = list1 ? list1 : list2;

    return dummy.next;
}

// Helper: build linked list from values vector
ListNode* createList(const vector<int>& vals)
{
    if (vals.empty()) return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *cur = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        cur->next = new ListNode(vals[i]);
        cur = cur->next;
    }
    return head;
}

// Helper: print list values
void printList(ListNode* head)
{
    bool first = true;
    for (ListNode* p = head; p; p = p->next)
    {
        if (!first) cout << " -> ";
        cout << p->val;
        first = false;
    }
    cout << "\n";
}

int main()
{
    // Example lists: merge [1,2,4] and [1,3,4]
    ListNode *a = createList({1,2,4});
    ListNode *b = createList({1,3,4});

    cout << "List A: ";
    printList(a);
    cout << "List B: ";
    printList(b);

    ListNode *merged = mergeTwoLists(a, b);
    cout << "Merged: ";
    printList(merged);

    // Note: nodes were allocated with new; skipping deletion for brevity.
    return 0;
}