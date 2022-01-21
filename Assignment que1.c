bool dfs(int curNode, int parent, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[curNode] = true;

    // Check all neighbours of current node
    for (int i = 0; i < graph[curNode].size(); i++)
    {
        int neighbour = graph[curNode][i];

        if (visited[neighbour] == false)
        {

            if (dfs(neighbour, curNode, graph, visited) == true)
            {
                return true;
            }
        }
        else
        {
            // Back-Edge found
            if (parent != neighbour)
            {
                return true;
            }
        }
    }
    return false;
}

bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
    vector<vector<int>> graph(n);
    vector<bool> visited(n, false);

    bool answer = true;

    // Build adjacency list graph
    for (int i = 0; i < edgeList.size(); i++)
    {
        int u = edgeList[i][0], v = edgeList[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Check for presence of cycle using dfs
    if (dfs(0, -1, graph, visited) == true)
    {
        answer = false;
    }

    // Check for multiple connected components
    for (int node = 0; node < n; node++)
    {
        if (visited[node] == false)
        {
            answer = false;
            break;
        }
    }

    return answer;
}
