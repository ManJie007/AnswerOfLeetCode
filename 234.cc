#include <vector>

using namespace std;

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
public:
  bool isPalindrome(ListNode *head) {
    if (head && head->next == nullptr) {
      return true;
    }

    vector<int> nums;
    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }

    int l = nums.size() / 2, r = nums.size() / 2;

    if (nums.size() % 2 == 0) {
      l = nums.size() / 2 - 1;
    }

    while (l >= 0 && r < nums.size()) {
      if (nums[l] != nums[r]) {
        return false;
      }
      l--;
      r++;
    }

    return true;
  }
};
