#include <vector>
#include <map>

using namespace std;

struct Num
{
    int limits;
    int cur_count;

    Num() : limits(0), cur_count(0) {}
    Num(int limits) : limits(limits), cur_count(1) {}
    Num(int limits, int cur_count) : limits(limits), cur_count(cur_count) {}
};

class Solution
{
private:
    map<int, Num> answer_num_map;

public:
    int numRabbits(vector<int> &answers)
    {
        int res = 0;
        for (size_t i = 0; i < answers.size(); i++)
        {
            int answer = answers[i];
            if (answer_num_map.find(answer) == answer_num_map.end())
            {
                answer_num_map.insert({answer, Num(answer + 1)});
            }
            else
            {
                Num tmpNum = answer_num_map[answer];
                if (tmpNum.limits > tmpNum.cur_count)
                {
                    answer_num_map[answer].cur_count++;
                }
                else
                {
                    // 满了
                    res += tmpNum.limits;
                    answer_num_map[answer].cur_count = 1;
                }
            }
        }

        for (auto &pair : answer_num_map)
        {
            res += pair.second.limits;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums{2, 1, 2, 2, 2, 2, 2, 2, 1, 1};
    Solution s;
    s.numRabbits(nums);
    return 0;
}
