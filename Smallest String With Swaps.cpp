// Appliacation of union and find 

class Solution {
public:
    int findParent(vector<int> &parents, int child)
    {
        return parents[child] < 0 ? child : parents[child] = findParent( parents, parents[child] );
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int>parents(s.size(),-1);
        vector<vector<int>>adj(s.size());
        // apply union and find to take the group of elements that belong to the same group and after that we form the string of the group and sort it in 
        // ascending order and after that traversing the index in the group and updating the shortest char poosible for that position.
        for( auto &it : pairs)
        {
            int first = findParent(parents,it[0]);
            int second = findParent(parents,it[1]);
            if(first != second)
            {
                parents[first] = second;
            }
        }
       // this store the index in sorted format for the group.
        for( auto i = 0 ; i < s.size() ; i++ )
        {
            adj[findParent(parents, i)].push_back(i);
        }
        for( auto &ids : adj)
        {
            string str = "";
            for( auto &id : ids )
                str+=s[id];
            sort(str.begin(), str.end());
            for( auto i = 0 ; i < ids.size() ; i++ )
            {
                s[ids[i]] = str[i];
            }      
        }
        return s;
    }
};
