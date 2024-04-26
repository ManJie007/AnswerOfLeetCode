#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
//    string removeDuplicates(string s) {
//        for(auto iter = s.begin(); iter != s.end(); ) {
//            if(iter + 1 != s.end() && *iter == *(iter + 1)) {
//                iter = s.erase(iter, iter + 2);
//                --iter;
//            }else {
//                ++iter;
//            }
//        }
//
//        return s;
//     }

    string removeDuplicates(string s) {
        
        stack<char> c_s;

        for(auto &ch : s ) {
            
            if(!c_s.empty() && ch == c_s.top()) {
                c_s.pop();
            }else {
                c_s.push(ch);
            }
        }
        
        string res;

        while (!c_s.empty()) {
            res += c_s.top();
            c_s.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

int main(int argc, char* argv[]) {
    
    string str = "aaihahcajchcghffjdcdiebbigjdihgcibifhacddacfcchhjdeibfgchdeihiegfibbeefcjaccbdeggjgdifeibbfeihfhgddd";
    Solution s;
    std::cout << s.removeDuplicates(str);

    return 0;
}
