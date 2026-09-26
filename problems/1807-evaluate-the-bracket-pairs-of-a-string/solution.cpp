class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (int i = 0; i < knowledge.size(); i++) {
            dict[knowledge[i][0]] = knowledge[i][1];
        }

        string result = "";
        int i = 0;
        int n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                int j = i + 1;
                string key = "";
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }

                if (dict.find(key) != dict.end()) {
                    result += dict[key];
                } else {
                    result += "?";
                }

                i = j + 1;
            } else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};