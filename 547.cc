#include <iostream>
#include <vector>

using namespace std;

class UF
{
public:
    UF(int n)
    {
        count = n;
        parent.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    void union_a_b(int a, int b)
    {
        int p_a = find_parent(a);
        int p_b = find_parent(b);

        if (p_a == p_b)
        {
            return;
        }

        parent[p_a] = p_b;
        count--;
    }

    int getCount()
    {
        return count;
    }

private:
    int count;
    vector<int> parent;

    int find_parent(int n)
    {
        while (n != parent[n])
        {
            parent[n] = parent[parent[n]];
            n = parent[n];
        }

        return n;
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UF uf(isConnected.size());

        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (i != j && isConnected[i][j] == 1)
                {
                    uf.union_a_b(i, j);
                }
            }
        }

        return uf.getCount();
    }
};