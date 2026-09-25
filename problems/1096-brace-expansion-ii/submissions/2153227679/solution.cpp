class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parse(expression, i);
        return vector<string>(result.begin(), result.end());
    }

    set<string> parse(string& s, int& i) {
        set<string> current = {""};  

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> next;

            if (s[i] == '{') {
                i++;                    
                next = parseUnion(s, i);  
                i++;                      
            } else {
                next = { string(1, s[i]) };
                i++;
            }

            current = product(current, next);  
        }

        return current;
    }


    set<string> parseUnion(string& s, int& i) {
        set<string> result;

        while (true) {
            set<string> piece = parse(s, i);  
            result = unite(result, piece);

            if (i < s.size() && s[i] == ',') {
                i++;      
            } else {
                break;    
            }
        }

        return result;
    }

    set<string> unite(set<string> A, set<string>& B) {
        for (const string& x : B) A.insert(x);
        return A;
    }

    set<string> product(set<string>& A, set<string>& B) {
        set<string> res;
        for (const string& a : A)
            for (const string& b : B)
                res.insert(a + b);
        return res;
    }
};