/*-------------------------Author: Hsin-Yu Hsieh-------------------------*/
/*First Trial:  2 pointers check directly      T:5 77.16%    M:7.5 58.62%*/
/*Second Trial: 2 pointers + anum func         T:75 5.46%    M:7.2 92.67%*/
/*Third Trial:  anum string + 2 pointer        T:7 65.41%    M:7.7 44.67%*/
/*Fourth Trial: anum string + reverse          T:3 95.22%    M:8   10.24%*/

class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for (int i=0; i<s.size(); i++)  if(isalnum(s[i]))   str+=(tolower(s[i]));
        string rev = str;
        reverse(rev.begin(), rev.end());
        return str==rev;
    }
};

/*
First Trial: Use two pointers to check directly
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            bool yi = ('0'<=s[i] && s[i]<='9')||('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z');
            bool yj = ('0'<=s[j] && s[j]<='9')||('a'<=s[j]&&s[j]<='z')||('A'<=s[j]&&s[j]<='Z');
            if(yi && yj){
                if(tolower(s[i])!=tolower(s[j]))    return false;
                i++;
                j--;
            }
            else if (yi)    j--;
            else if (yj)    i++;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
*/

/*
Second Trial: Use a function to compute until s[w] is anum
class Solution {
public:
    void ch(int &w, string &s, int changes){
        while(!(('0'<=s[w] && s[w]<='9')||('a'<=s[w]&&s[w]<='z')||('A'<=s[w]&&s[w]<='Z')) && w+changes>=0 && w+changes<s.size()){
            w+=changes;
        }
        if ('A'<=s[w] && s[w]<='Z') s[w] = tolower(s[w]);
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while(i<j){
            ch(i, s, 1);
            ch(j, s, -1);
            cout << i<< " "<<j<<endl;
            if (i>=j)    return true;
            if((s[i])!=(s[j]))    return false;
            i++;
            j--;
        }
        return true;
    }
};
*/

/*
Third Trial:  anum string + 2 pointer
class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for (int i=0; i<s.size(); i++)  if(isalnum(s[i]))   str+=(tolower(s[i]));
        int l=0, r=str.size()-1;
        while(l<r){
            if (str[l]!=str[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
*/