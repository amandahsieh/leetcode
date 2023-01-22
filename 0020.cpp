/*-----------------------------Author: Hsin-Yu Hsieh-----------------------------*/
/*First Trial: stack (unordered map / auto)              T:0 100%    M:6.2 81.20%*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(st.empty())  return false;
                if(st.top()=='(' && s[i]==')')  st.pop();
                else if(st.top()=='[' && s[i]==']')  st.pop();
                else if(st.top()=='{' && s[i]=='}')  st.pop();
                else    return false;
            }
            else    st.push(s[i]);
        }
        if(!st.empty()) return false;
        return true;
    }
};

/*
unordered map
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char, int> mp{{'(',0},{')',1},{'[',2},{']',3},{'{',4},{'}',5}};
        for(int i=0; i<s.size(); i++){
            if(s[i]==')' || s[i]==']' || s[i]=='}'){
                if(st.empty())  return false;
                if(st.top()==mp[s[i]]-1)  st.pop();
                else    return false;
            }
            else    st.push(mp[s[i]]);
        }
        if(!st.empty()) return false;
        return true;
    }
};
*/

/*
auto
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(' || i=='[' || i=='{')  st.push(i);
            else{
                if(st.empty())  return false;
                if((i==')'&&st.top()=='(')||(i==']'&&st.top()=='[')||(i=='}'&&st.top()=='{'))   st.pop();
                else    return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
*/