class Solution {
public:
    string reverseWords(string s) {
        int end, start = 0; //end more or less represents the end of a word
        while (s[start] == ' ') { //erase beginning spaces
            s.erase(s.begin());
        } 
        
        reverse(s.begin(), s.end()); //reverse entire string
        
        while (s[start] == ' ') { //erase ending spaces which are now in front
            s.erase(s.begin());
        } 
        
        while ((end = s.find(" ", start)) != string::npos) { //while the last found space is not the end of string
            reverse(s.begin() + start, s.begin() + end); //reverse the 'space' that the next string takes up
            while (s[end+1] == ' ' && ((end+1) < s.size())) {
                 s.erase(s.begin() + (end + 1));
            }
            start = end + 1;
            
        }
        
        reverse(s.begin() + start, s.end()); //reverse last word
        return s;
    }
};