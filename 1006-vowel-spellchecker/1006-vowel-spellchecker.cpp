class Solution
{
public:

    string tolower(string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    string discardVowels(string s)
    {
        for(char &c : s)
        {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    {
                        c = '#';
                    }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordList, vector<string>& queries)
    {
        unordered_set<string> exact;
        for(auto s : wordList) exact.insert(s);

        unordered_map<string, int> lower;

        for(int i = 0; i < wordList.size(); i++)
        {
            if(lower.find(tolower(wordList[i])) == lower.end())
            {
                lower.insert({tolower(wordList[i]), i});
            }
        }

        unordered_map<string, int> withoutVowels;

        for(auto e : lower)
        {
            string s = e.first;
            int index = e.second;
            string noVowel = discardVowels(s);

            if(withoutVowels.find(noVowel) == withoutVowels.end())
            {
                withoutVowels.insert({noVowel, index});
            }
            else if(withoutVowels[noVowel] > index)
            {
                withoutVowels.erase(noVowel);
                withoutVowels.insert({noVowel, index});
            }
        }

        vector<string> result;

        for(auto q : queries)
        {
            if(exact.find(q) != exact.end())
            {
                result.push_back(q);
            }
            else
            {
                // Sacrifice 1 :- lower-case
                q = tolower(q);

                if(lower.find(q) != lower.end())
                {
                    int i = lower[q];
                    result.push_back(wordList[i]);
                }
                else
                {
                    // Sacrifice 2 :- vowel
                    q = discardVowels(q);

                    if(withoutVowels.find(q) != withoutVowels.end())
                    {
                        int i = withoutVowels[q];
                        result.push_back(wordList[i]);
                    }
                    else
                    {
                        // NaH Mate.
                        result.push_back("");
                    }
                    
                }
            }
        }

        return result;
    }
};