/*-----------------Author: Hsin-Yu Hsieh-----------------*/
/*First Trial: stack           T:12 64.88%    M:12 72.29%*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st(tokens.size());
        int tmp = 0;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i]=="+"){
                int a = st[--tmp];
                int b = st[tmp-1];
                st[tmp-1]=(b+a);
            }
            else if(tokens[i]=="-"){
                int a = st[--tmp];
                int b = st[tmp-1];
                st[tmp-1]=(b-a);
            }
            else if(tokens[i]=="*"){
                int a = st[--tmp];
                int b = st[tmp-1];
                st[tmp-1]=(b*a);
            }
            else if(tokens[i]=="/"){
                int a = st[--tmp];
                int b = st[tmp-1];
                st[tmp-1]=(b/a);
            }
            else{
                int num = 0, n = 1;
                for(int j=0; j<tokens[i].size(); j++){
                    if(tokens[i][j]=='-')   n=-1;
                    else    num = num*10+tokens[i][j]-'0';
                }
                st[tmp++] = num*n;
            }
        }
        return st[0];
    }
};