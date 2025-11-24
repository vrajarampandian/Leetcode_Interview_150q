#include<iostream>
#include<vector>
using namespace std;

// Definition for singly-linked list node.
// val : stored value
// next: pointer to the next node (nullptr for tail)
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Reverse a singly-linked list iteratively.
    // Input: head pointer to the list (may be nullptr).
    // Returns: new head pointer of the reversed list.
    //
    // Algorithm (in-place, iterative):
    // - Maintain prev (initially nullptr) and curr (initial head).
    // - Repeatedly detach curr->next into tmp, point curr->next to prev,
    //   advance prev = curr and curr = tmp.
    // - When curr becomes nullptr, prev is new head.
    //
    // Time: O(n), Space: O(1).
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while(curr)
        {
            ListNode *tmp = curr->next; // save next node
            curr->next = prev;          // reverse pointer
            prev = curr;                // advance prev
            curr = tmp;                 // advance curr
        }

        return prev; // new head
    }
};

// Helper: create linked list from vector and return head
// Usage: createList({1,2,3}) -> head of 1->2->3
ListNode* createList(const vector<int>& vals)
{
    if (vals.empty()) return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *tail = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        tail->next = new ListNode(vals[i]);
        tail = tail->next;
    }
    return head;
}

// Helper: print linked list values in readable form "1 -> 2 -> 3"
void printList(ListNode* head)
{
    ListNode* cur = head;
    while (cur)
    {
        cout << cur->val;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    cout << "\n";
}

int main()
{
    // Example: build list 1->2->3->4->5
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* rev = sol.reverseList(head);

    cout << "Reversed list: ";
    printList(rev);

    // Note: nodes are allocated with new; for brevity we don't free them here.
    return 0;
}