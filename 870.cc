#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct num
{
    size_t m_i;
    int m_val;

    num() : m_i(0), m_val(0) {}
    num(size_t i, int val) : m_i(i), m_val(val) {}
};

// 从大到小排序
bool compareNum(const num &lhs, const num &rhs)
{
    return lhs.m_val < rhs.m_val;
}

class Solution
{
public:
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2)
    {
        // priority_queue<num, vector<num>, bool(*)(const num &lhs, const num &rhs)> pq(compareNum);
        priority_queue<num, vector<num>, decltype(compareNum) *> pq(compareNum);
        for (size_t i = 0; i < nums2.size(); i++)
        {
            pq.push(num(i, nums2[i]));
        }

        // while (!pq.empty())
        // {
        //     num tmpNum = pq.top();
        //     pq.pop();
        //     cout << tmpNum.m_i << " " << tmpNum.m_val << endl;
        // }

        // 从大到小排序
        sort(nums1.begin(), nums1.end(), greater<int>());
        // for (auto i : nums1)
        // {
        //     cout << i << " ";
        // }

        vector<int> res;
        res.resize(nums1.size(), 0);
        int left = 0, right = nums1.size() - 1;
        while (!pq.empty())
        {
            num tmpNum = pq.top();
            pq.pop();

            if (nums1[left] > tmpNum.m_val)
            {
                res[tmpNum.m_i] = nums1[left];
                left++;
            }
            else
            {
                res[tmpNum.m_i] = nums1[right];
                right--;
            }
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{2, 7, 11, 15};
    vector<int> nums2{1, 10, 4, 11};
    Solution sloution;
    sloution.advantageCount(nums1, nums2);
    return 0;
}
