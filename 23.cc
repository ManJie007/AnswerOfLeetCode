#include <vector>
#include <queue>
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

bool compareListNodePtr(const ListNode *lhs, const ListNode *rhs)
{
    return lhs->val > rhs->val;
}

class Solution
{
private:
    ListNode *initListNode(const vector<int> &vec)
    {
        ListNode head;
        ListNode *headPtr = &head;

        for (size_t i = 0; i < vec.size(); i++)
        {
            ListNode *newNode = new ListNode(vec[i]);
            headPtr->next = newNode;
            headPtr = headPtr->next;
        }

        return head.next;
    }

public:
    vector<ListNode *> initListNodeVec(const vector<vector<int>> &vecs)
    {
        vector<ListNode *> result;

        for (size_t i = 0; i < vecs.size(); i++)
        {
            const vector<int> &vec = vecs[i];
            result.push_back(initListNode(vec));
        }

        return result;
    }

    void printListNodeVec(vector<ListNode *> &nodeVec)
    {
        for (size_t i = 0; i < nodeVec.size(); i++)
        {
            ListNode *tmp = nodeVec[i];

            while (tmp != nullptr)
            {
                cout << tmp->val << " -> ";
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void printListNode(ListNode *tmp)
    {
        while (tmp != nullptr)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, decltype(compareListNodePtr) *> pq(&compareListNodePtr);
        for (size_t i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
                pq.push(lists[i]);
        }

        ListNode mergHead;
        ListNode *ptr = &mergHead;
        while (pq.size() != 0)
        {
            ListNode *tmp = pq.top();
            pq.pop();
            ptr->next = tmp;
            ptr = ptr->next;
            if (tmp != nullptr && tmp->next != nullptr)
                pq.push(tmp->next);
        }

        return mergHead.next;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<vector<int>> vecs{
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}};
    // vector<vector<int>> vecs{
    //     {3, 4, 5},
    //     {1, 3, 4},
    //     {4, 6}};
    vector<ListNode *> vec = solution.initListNodeVec(vecs);
    solution.printListNodeVec(vec);
    solution.printListNode(solution.mergeKLists(vec));
    return 0;
}