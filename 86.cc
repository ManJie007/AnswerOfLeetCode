#include <vector>
#include <iostream>

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
    ListNode *initListNode(const vector<int> &vec)
    {
        ListNode head;
        ListNode *headPtr = &head;

        for (size_t i = 0; i < vec.size(); i++)
        {
            int val = vec[i];
            headPtr->next = new ListNode(val);
            headPtr = headPtr->next;
        }

        return head.next;
    }

    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode tmpNode1, tmpNode2;
        ListNode *head1 = &tmpNode1, *head2 = &tmpNode2;
        while (head != nullptr)
        {
            if (head->val < x)
            {
                head1->next = head;
                head1 = head1->next;
            }
            else
            {
                head2->next = head;
                head2 = head2->next;
            }
            head = head->next;
        }
        head1->next = nullptr;
        head2->next = nullptr;

        if (head1 != &tmpNode1)
        {
            if (tmpNode2.next != nullptr)
            {
                head1->next = tmpNode2.next;
            }
            return tmpNode1.next;
        }
        else
        {
            return tmpNode2.next;
        }
    }
};

void printListNode(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    vector vec{1, 4, 3, 2, 5, 2};
    ListNode *head = solution.initListNode(vec);
    printListNode(head);
    printListNode(solution.partition(head, 3));

    return 0;
}
