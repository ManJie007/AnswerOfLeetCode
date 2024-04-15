#include <utility>

using namespace std;

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
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = 0;
        ListNode *tmp = l1;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            ++len1;
        }

        int len2 = 0;
        tmp = l2;
        while (tmp != nullptr)
        {
            tmp = tmp->next;
            ++len2;
        }

        if (len2 > len1)
            swap(l1, l2);

        tmp = l1;
        ListNode *pre = tmp, *tmp2 = l2;
        int add = 0;
        while (tmp != nullptr)
        {
            if (tmp2 != nullptr)
            {
                int sum = tmp->val + tmp2->val + add;
                tmp->val = sum % 10;
                add = sum / 10;

                pre = tmp;
                tmp = tmp->next;
                tmp2 = tmp2->next;
            }
            else
            {
                int sum = tmp->val + add;
                tmp->val = sum % 10;
                add = sum / 10;

                pre = tmp;
                tmp = tmp->next;
            }
        }

        if (add == 1)
        {
            pre->next = new ListNode(add);
        }

        return l1;
    }
};