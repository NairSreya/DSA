class Solution {
private:
    bool isValid(char ch){
        return (ch>='a'&&ch<='z' || ch>='A'&&ch<='Z'||ch>='0' && ch<='9');
    }

    char isChar(char ch){
        if(ch>='A'&&ch<='Z'){
            return ch - 'A'+'a';
        }
        return ch;
    }

    bool checkPalindrome(string a){
        int st = 0;
        int e = a.size()-1;

        while(st<e){
            if(a[st]!=a[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0; i<s.size();i++){
            if(isValid(s[i])){
                temp.push_back(isChar(s[i]));

            }
        }
        return checkPalindrome(temp);
        
    }
};