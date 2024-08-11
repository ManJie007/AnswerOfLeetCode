#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  void print_dp(const vector<vector<int>> &dp, int n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  }

  string longestPalindrome(string s) {
    int n = s.size();

    if (n < 2) {
      return s;
    }

    int maxLen = 1;
    int begin = 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
      dp[i][i] = 1;
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i < n; ++i) {
        int j = i + len - 1;

        if (j >= n)
          break;

        if (s[i] != s[j]) {
          dp[i][j] = 0;
        } else {
          if (j - i < 3) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }

        // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
        // 是回文，此时记录回文长度和起始位置
        if (dp[i][j] && j - i + 1 > maxLen) {
          maxLen = j - i + 1;
          begin = i;
        }
      }
    }

    return s.substr(begin, maxLen);
  }
};


/**
diff --git a/5.cc b/5.cc
index f66c886..2b2fb4e 100644
--- a/5.cc
+++ b/5.cc
@@ -1,54 +1,62 @@
+#include <iostream>
 #include <string>
+#include <vector>
 
 using namespace std;
 
-class Solution
-{
-private:
-    string isPalindromicString(const string &s, int l, int r)
-    {
-        if (l == r)
-        {
-            // 回文串为奇数
-            while ((l - 1) >= 0 && (r + 1 < s.size()) && s[l - 1] == s[r + 1])
-            {
-                --l;
-                ++r;
-            }
-            return s.substr(l, r - l + 1);
-        }
-        else
-        {
-            // 回文串为偶数
-            if (s[l] == s[r])
-            {
-                while ((l - 1) >= 0 && (r + 1 < s.size()) && s[l - 1] == s[r + 1])
-                {
-                    --l;
-                    ++r;
-                }
-                return s.substr(l, r - l + 1);
-            }
-            else
-            {
-                return s.substr(l, 1);
-            }
-        }
+class Solution {
+public:
+  void print_dp(const vector<vector<int>> &dp, int n) {
+    for (int i = 0; i < n; ++i) {
+      for (int j = 0; j < n; ++j) {
+        cout << dp[i][j] << " ";
+      }
+      cout << endl;
     }
+  }
 
-public:
-    string longestPalindrome(string s)
-    {
-        string res;
-        for (size_t i = 0; i < s.size(); i++)
-        {
-            string s1 = isPalindromicString(s, i, i);
-            string s2 = isPalindromicString(s, i, i + 1);
-
-            if (s1.length() > res.length())res = s1;
-            if (s2.length() > res.length())res = s2;
+  string longestPalindrome(string s) {
+    int n = s.size();
+
+    if (n < 2) {
+      return s;
+    }
+
+    int maxLen = 1;
+    int begin = 0;
+
+    vector<vector<int>> dp(n, vector<int>(n, 0));
+
+    for (int i = 0; i < n; ++i) {
+      dp[i][i] = 1;
+    }
+
+    for (int len = 2; len <= n; ++len) {
+      for (int i = 0; i < n; ++i) {
+        int j = i + len - 1;
+
+        if (j >= n)
+          break;
+
+        if (s[i] != s[j]) {
+          dp[i][j] = 0;
+        } else {
+          if (j - i < 3) {
+            dp[i][j] = 1;
+          } else {
+            dp[i][j] = dp[i + 1][j - 1];
+          }
         }
 
-        return res;
+        // 只要 dp[i][L] == true 成立，就表示子串 s[i..L]
+        // 是回文，此时记录回文长度和起始位置
+        if (dp[i][j] && j - i + 1 > maxLen) {
+          maxLen = j - i + 1;
+          begin = i;
+        }
+      }
     }
-};
\ No newline at end of file
+
+    return s.substr(begin, maxLen);
+  }
+};
*/
