#include <iostream>

using namespace std;

// Definition for singly-linked list
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextNode = nullptr;

        while (curr != nullptr)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr != nullptr)
        {
            if (curr->val == val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    // Create the linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    // Create a solution object
    Solution solution;

    // Reverse the linked list
    ListNode *reversedHead = solution.reverseList(head);
    cout << "Reversed List: ";
    printList(reversedHead);

    // Remove elements from the linked list
    ListNode *newList = solution.removeElements(reversedHead, 6);
    cout << "List after removing elements: ";
    printList(newList);

    // Clean up memory
    ListNode *curr = newList;
    while (curr != nullptr)
    {
        ListNode *temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}
