class Solution
{
public:
    bool isValid(string word)
    {
        if(word.length() < 3) return false;
        bool vowel = false, consonant = false;
        set<char> vc = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(auto c : word) {
            if(vc.find(c) != vc.end()) {
                vowel = true;
            }
            else {
                if(c >= '1' && c <= '9') continue;
                else if(c == '@' || c == '#' || c == '$') return false;
                else consonant = true;
            }
        }
        return (vowel & consonant);
    }
};