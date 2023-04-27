/*------------------Author: Hsin-Yu Hsieh-------------------*/
/*First Trial:  Kruskal          T:808 41.54%  M:58.3 58.59%*/
/*Second Trial: Prime's          T: 73 98.84%  M:10.2 91.62%*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0, i = 0, connected = 0, minj=0;
        vector<int> mindis(n, INT_MAX-10);
        while(++connected<n){
            mindis[i]=INT_MAX;
            for(int j=0; j<n; j++){
                if(mindis[j]==INT_MAX)  continue;
                mindis[j]=min(mindis[j],(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])));
                minj = (mindis[j]<mindis[minj])? j:minj;
            }
            ans += mindis[minj];
            i = minj;
        }
        return ans;
    }
};

/*
First Trial:
class Solution {
public:
    vector<int> group;
    class edge{
    public:
        int a;
        int b;
        int cost;
    };
    struct mycmp{
        bool operator()(edge a, edge b){
            return a.cost<b.cost;
        }
    };
    int look(int a){
        if(group[a]==a) return a;
        else    return look(group[a]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(), ans = 0, i, j;
        vector<edge> dis;
        for(i=0; i<n; i++){
            for(j=i+1; j<n; j++){
                edge tmp;
                tmp.a = i;
                tmp.b = j;
                tmp.cost = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                dis.push_back(tmp);
            }
        } 
        sort(dis.begin(), dis.end(), mycmp());
        group.resize(n);
        for(i=0; i<n; i++)  group[i]=i;
        for(i=0; i<dis.size(); i++){
            int l1=look(dis[i].a), l2=look(dis[i].b);
            if(l1==l2)  continue;
            ans+=dis[i].cost;
            group[l2] = l1;
        }
        return ans;
    }
};
*/