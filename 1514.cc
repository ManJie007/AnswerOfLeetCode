#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int from, to;
    double weight;

    Edge(int from, int to, double weight) : from(from), to(to), weight(weight) {}
};

struct State
{
    int id;
    double proFromStart;
    State(int id, double proFromStart) : id(id), proFromStart(proFromStart) {}
};

bool compareState(const State &a, const State &b)
{
    return a.proFromStart < b.proFromStart;
}

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<Edge>> graph;
        graph.resize(n);

        for (size_t i = 0; i < edges.size(); i++)
        {
            auto &vec = edges[i];
            int from = vec[0];
            int to = vec[1];

            graph[from].push_back({from, to, succProb[i]});
            graph[to].push_back({to, from, succProb[i]});
        }

        vector<double> proTo;
        proTo.resize(n, -1);

        proTo[start_node] = 1;

        priority_queue<State, vector<State>, decltype(compareState) *> pq(compareState);

        pq.push({start_node, 1});

        while (!pq.empty())
        {
            State curState = pq.top();
            pq.pop();
            int curNodeID = curState.id;
            double curProbFromStart = curState.proFromStart;
            // 遇到终点提前返回
            if (curNodeID == end_node)
            {
                return curProbFromStart;
            }

            if (curProbFromStart < proTo[curNodeID])
            {
                // 已经有⼀条概率更⼤的路径到达 curNode 节点了
                continue;
            }
            // 将 curNode 的相邻节点装⼊队列
            for (auto &neighbor : graph[curNodeID])
            {
                int nextNodeID = neighbor.to;
                // 看看从 curNode 达到 nextNode 的概率是否会更⼤
                double probToNextNode = proTo[curNodeID] * neighbor.weight;
                if (proTo[nextNodeID] < probToNextNode)
                {
                    proTo[nextNodeID] = probToNextNode;
                    pq.push({nextNodeID, probToNextNode});
                }
            }
        }
        return 0.0;
    }
};
