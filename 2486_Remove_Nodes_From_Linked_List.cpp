/*--------------------------Author: Hsin-Yu Hsieh--------------------------*/
/*First Trial: Traverse of s to see the same     T:18 84.69%  M:10.7 88.19%*/
class Solution{
public:
	int appendCharacters(string s, string t){
		int ans=0;
		for(int i=0; i<s.size(); i++){
			if(s[i]==t[ans])	ans++;
		}
		return t.size()-ans;
	}
};