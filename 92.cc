struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
private:
    ListNode *record = nullptr;

    ListNode *reverseN(ListNode *head, int n)
    {
        // base case
        if (n == 1)
        {
            record = head->next;
            return head;
        }

        ListNode *last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = record;

        return last;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == 1)
        {
            return reverseN(head, right);
        }

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};