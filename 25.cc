struct ListNode {
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
class Solution {
private:
  void reverse(ListNode *head, ListNode *tail) {
    ListNode *pre = nullptr, *cur = head;

    while (pre != tail) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode dummy;
    dummy.next = head;

    ListNode *pre = &dummy, *next = head;

    while (next != nullptr) {
      ListNode *begin = next, *end = next;

      for (int i = 0; i < k - 1; ++i) {
        end = end->next;
        if (end == nullptr) {
          goto end;
        }
      }

      next = end->next;

      reverse(begin, end);
      pre->next = end;
      begin->next = next;

      pre = begin;
    }
end:
    return dummy.next;
  }
};

int main(int argc, char** argv) {

    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution s;
    s.reverseKGroup(n1, 1);

    return 0;
}
