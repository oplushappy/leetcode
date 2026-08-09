class UnionFind {
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if(x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unionSets(int x1, int x2) {
        int p1 = find(x1);
        int p2 = find(x2);
        if(p1 == p2) return false;
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // email -> idx
        unordered_map<string, int> emailToAccIdx;
        UnionFind uf(accounts.size());

        for(int i = 0; i < accounts.size(); i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string e = accounts[i][j];
                if(emailToAccIdx.count(e)) {
                    uf.unionSets(i, emailToAccIdx[e]);
                } else {
                    emailToAccIdx[e] = i;
                }
            }
        }

        unordered_map<int, vector<string>> emailGroup;
        for(auto [e, idx] : emailToAccIdx) {
            int leader = uf.find(idx);
            emailGroup[leader].push_back(e);
        }

        vector<vector<string>> res;
        for(auto &[idx, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            string name = accounts[idx][0];
            vector<string> tmp;
            tmp.push_back(name);
            tmp.insert(tmp.end(), emails.begin(), emails.end());
            res.push_back(tmp);
        }
        return res;
    }
};