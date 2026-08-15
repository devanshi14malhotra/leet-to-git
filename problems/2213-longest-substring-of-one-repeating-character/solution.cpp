class Solution {
public:
    struct Node {
        char leftChar;
        char rightChar;
        int leftRun;
        int rightRun;
        int best;
        int length;
    };

    vector<Node> tree;
    string str;

    Node combine(Node left, Node right) {
        Node result;
        result.length = left.length + right.length;
        result.leftChar = left.leftChar;
        result.rightChar = right.rightChar;

        result.leftRun = left.leftRun;
        if (left.leftRun == left.length && left.rightChar == right.leftChar) {
            result.leftRun = left.leftRun + right.leftRun;
        }

        result.rightRun = right.rightRun;
        if (right.rightRun == right.length && right.leftChar == left.rightChar) {
            result.rightRun = right.rightRun + left.rightRun;
        }

        result.best = max(left.best, right.best);
        if (left.rightChar == right.leftChar) {
            result.best = max(result.best, left.rightRun + right.leftRun);
        }

        return result;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            Node leaf;
            leaf.leftChar = str[start];
            leaf.rightChar = str[start];
            leaf.leftRun = 1;
            leaf.rightRun = 1;
            leaf.best = 1;
            leaf.length = 1;
            tree[node] = leaf;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int start, int end, int index, char newChar) {
        if (start == end) {
            Node leaf;
            leaf.leftChar = newChar;
            leaf.rightChar = newChar;
            leaf.leftRun = 1;
            leaf.rightRun = 1;
            leaf.best = 1;
            leaf.length = 1;
            tree[node] = leaf;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid) {
            update(2 * node + 1, start, mid, index, newChar);
        } else {
            update(2 * node + 2, mid + 1, end, index, newChar);
        }
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2]);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        int n = s.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);

        int k = queryIndices.size();
        vector<int> answer(k);
        for (int i = 0; i < k; i++) {
            update(0, 0, n - 1, queryIndices[i], queryCharacters[i]);
            answer[i] = tree[0].best;
        }
        return answer;
    }
};