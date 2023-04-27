/*----------------------Author: Hsin-Yu Hsieh--------------------*/
/*First Trial:  Recursive, Tree         T:3 75.43%  M:11.1 56.75%*/
/*Second Trial: Recursive, Tree, empty  T:0 100%    M:11.1 56.75%*/

class Solution {
public:
    int cal(int x, int y, char op){
        if(op=='+') return x+y;
        else if(op=='-')    return x-y;
        else    return x*y;
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        for(int i=0; i<expression.size(); i++){
            if(!isdigit(expression[i])){
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right= diffWaysToCompute(expression.substr(i+1));
                for(int x:left){
                    for(int y:right){
                        int tmp = cal(x, y, expression[i]);
                        results.push_back(tmp);
                    }
                }
            }
        }
        if(results.empty())   results.push_back(stoi(expression));
        return results;
    }
};

/*
First Trial:
class Solution {
public:
    int cal(int x, int y, char op){
        if(op=='+') return x+y;
        else if(op=='-')    return x-y;
        else if(op=='*')    return x*y;
        else        return x/y;
    }
    vector<int> diffWaysToCompute(string expression) {
        bool isNum = 1;
        vector<int> results;
        for(int i=0; i<expression.size(); i++){
            if(!isdigit(expression[i])){
                isNum = 0;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right= diffWaysToCompute(expression.substr(i+1));
                for(int x:left){
                    for(int y:right){
                        int tmp = cal(x, y, expression[i]);
                        results.push_back(tmp);
                    }
                }
            }
        }
        if(isNum)   results.push_back(stoi(expression));
        return results;
    }
};
*/