class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> result = parse(expression, i);
        return vector<string>(result.begin(), result.end());
    }

    // Parses ONE full expression starting at i (a run of concatenated pieces),
    // and returns the set of words that expression represents.
    // Stops when it hits ',' or '}' or end of string.
    set<string> parse(string& s, int& i) {
        set<string> current = {""};   // identity for concatenation, like current = a×b×c...

        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> next;

            if (s[i] == '{') {
                i++;                      // consume '{'
                next = parseUnion(s, i);  // resolve whole {...} into one set
                i++;                      // consume '}'
            } else {
                next = { string(1, s[i]) };
                i++;
            }

            current = product(current, next);  // concatenate onto what we have so far
        }

        return current;
    }

    // Handles the comma-separated alternatives inside one {...}.
    // Parses each alternative with parse(), unions them all together.
    set<string> parseUnion(string& s, int& i) {
        set<string> result;

        while (true) {
            set<string> piece = parse(s, i);   // one comma-separated alternative
            result = unite(result, piece);

            if (i < s.size() && s[i] == ',') {
                i++;        // skip ',' and parse the next alternative
            } else {
                break;      // hit '}' -> this union is done
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