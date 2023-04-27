/*------------------------Author: Hsin-Yu Hsieh------------------------*/
/*First Trial: revealing order *Queue & Sort   T:0 100%  M:8.4 87.20%*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n=deck.size(), i=0;
	    queue<int> q;   //revealing order
	    vector<int> ans(n, 0);
	    while(i<n)	q.push(i++);
	    for(i=0; i<n; i++){
		    ans[q.front()] = deck[i];
		    q.pop();
		    q.push(q.front());
		    q.pop();
	    }
	  return ans;
    }
};