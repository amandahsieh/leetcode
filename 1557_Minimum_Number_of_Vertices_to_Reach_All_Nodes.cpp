/*------------------Author: Hsin-Yu Hsieh-------------------*/
/*First Trial:  Kruskal          T:309 76.31%  M:93.9 93.89%*/
/*Second Trial: Indegree=0       T:246 99.95%  M:94.3 87.55%*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        vector<int> tmp(n,0),ans;
        int i, m=edges.size();
        for(i=0; i<m; i++)   tmp[edges[i][1]]++;
        for(i=0;i<n;i++) if(!tmp[i])  ans.push_back(i);
        return ans;
    }
};

/*
First Trial:
class Solution {
public:
    vector<int> group;
    int look(int x){
        if(x==group[x]) return x;
        return look(group[x]);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        group.resize(n);
        for(int i=0; i<n; i++)  group[i]=i;
        for(int i=0; i<edges.size(); i++){
            int l1 = look(edges[i][0]), l2 = look(edges[i][1]);
            group[edges[i][1]]=l1;
        }
        for(int i=0; i<n; i++)  group[i]=look(i);
        sort(group.begin(), group.end());
        group.erase(unique(group.begin(), group.end()), group.end());
        return group;
    }
};
*/