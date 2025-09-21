class Solution {
public:
    int romanToInt(string s) {
        map<char, int> values;
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;
        int n = s.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            if(i+1<n){
                if(values[s[i]]<values[s[i+1]]){
                    ans-= values[s[i]];
                }else{
                    ans+= values[s[i]];
                }
            }else{
                ans+= values[s[i]];
            }
        }
        return ans;

        
    }
};