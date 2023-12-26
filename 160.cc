#include <cstddef>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tmpPtr1 = headA, *tmpPtr2 = headB;
        bool flagA = false, flagB = false;

        while (tmpPtr1 != nullptr || tmpPtr2 != nullptr)
        {

            if (tmpPtr1 == tmpPtr2)
            {
                return tmpPtr1;
            }

            if (tmpPtr1 == nullptr && !flagA)
            {
                flagA = true;
                tmpPtr1 = headB;
                tmpPtr2 = tmpPtr2->next;
            }
            else if (tmpPtr2 == nullptr && !flagB)
            {
                flagB = true;
                tmpPtr2 = headA;
                tmpPtr1 = tmpPtr1->next;
            }
            else
            {
                tmpPtr1 = tmpPtr1->next;
                tmpPtr2 = tmpPtr2->next;
            }
        }

        return nullptr;
    }
};