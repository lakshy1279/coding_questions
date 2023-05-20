// You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot be determined, return -1.0.

//EX: Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
//Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]

// choose unordered_map to build the graph as we want to make string as the index.
// a -> {b , 2.00} b -> {c, 3.00}  if we want to found a / c then we tarvserse edges from a then move to b and trverse edges from b if we find c then return the val 3.00 otherwise return 0; b and c cancel each othee. a/b * b/c ...;

class Solution {
public:
    unordered_map<string, unordered_map<string,double>> makeGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        unordered_map<string, unordered_map<string,double>>graph;
        for(int i = 0; i < equations.size(); i++)
        {
            string first = equations[i][0];
            string second = equations[i][1];
            double value = values[i];
            graph[first].insert({second, value});
            graph[second].insert({first, 1 / value});
        } 
        return graph;
    }
    double dfs(unordered_map<string, unordered_map<string,double>> &graph, string first, string second, unordered_set<string>&st)
    {
         if(graph[first].find(second) != graph[first].end())
         return graph[first][second];
         st.insert(first);
         for(auto &it : graph[first])
         {
             if(st.find(it.first) == st.end())
             {
                 double temp = dfs(graph, it.first, second, st);
                 if(temp)
                 return temp * it.second;
             }
         }
         return 0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        unordered_map<string, unordered_map<string,double>> graph = makeGraph(equations, values);
        for(int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> st;
           double result = dfs(graph, queries[i][0], queries[i][1], st);
           if(result)
           ans.push_back(result);
           else
           ans.push_back(-1);
        }
        return ans;
    }
};