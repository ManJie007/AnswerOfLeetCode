#include <vector>
#include <map>
#include <stack>
#include <iostream>

using namespace std;

class Solution
{
private:
    // 保存数值和下一个更大元素的映射
    map<int, int> indexValueMap;

public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> intStack;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!intStack.empty() && nums2[i] > intStack.top())
            {
                intStack.pop();
            }

            int value = intStack.empty() ? -1 : intStack.top();
            intStack.push(nums2[i]);

            indexValueMap.insert(make_pair(nums2[i], value));
        }

        // auto iter = indexValueMap.begin();
        // while (iter != indexValueMap.end())
        // {
        //     cout << iter->first << " " << iter->second << endl;
        //     ++iter;
        // }

        vector<int> res;
        res.resize(nums1.size(), -1);
        for (size_t i = 0; i < nums1.size(); i++)
        {
            res[i] = indexValueMap[nums1[i]];
        }
        

        return res;    
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1{4, 1, 2};
    vector<int> nums2{1, 3, 4, 2};
    Solution solution;
    solution.nextGreaterElement(nums1, nums2);

    return 0;
}
