// Ques : You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).

// The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.

// There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, costi] indicates that the ith special road can take you from (x1i, y1i) to (x2i, y2i) with a cost equal to costi. You can use each special road any number of times.

// Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

// in this we start with make edge from start to every road and pick the min one and proceed with that and again made edge
// from this node to all other special rodes if cost to travel that road is less than curr cost of that road then we move forward with that.

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& end, vector<vector<int>>& roads) {
          int n = roads.size();
          vector<int>dist(n, INT_MAX);
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          for(int i = 0; i < n; i++)
          {
              int dis = abs(start[0] - roads[i][0]) + abs(start[1] - roads[i][1]) + roads[i][4];
              dist[i] = dis;
              pq.push({dist[i], i});
          }
          int ans = abs(start[0] - end[0]) + abs(start[1] - end[1]);
          while(!pq.empty())
          {
              auto [dis, node] = pq.top();
              pq.pop();
              if(dist[node] != dis)
                  continue;
              for(int i = 0; i < n; i++)
              {
                  ans = min(ans, dis +  abs(roads[node][2] - end[0]) + abs(roads[node][3] - end[1]));
                  int currdis = abs(roads[node][2] - roads[i][0]) + abs(roads[node][3] - roads[i][1]) + roads[i][4];
                  if(dist[i] > dis + currdis)
                  {
                      dist[i] = currdis + dis;
                      pq.push({dist[i], i});
                  }
              }
          }
        return ans;
}
