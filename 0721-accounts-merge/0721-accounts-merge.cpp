class UnionFind {
public:
    unordered_map<string, string> parent;

    string find(string x) {
        if (parent.find(x) == parent.end()) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(string x, string y) {
        string rootX = find(x);
        string rootY = find(y);
        if (rootX != rootY) parent[rootX] = rootY;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf;
        unordered_map<string, string> emailToName;

        // Bước 1: Union các email trong cùng account
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                uf.unite(account[1], account[i]); // nối với email đầu tiên
                emailToName[account[i]] = name;
            }
        }

        // Bước 2: Gom email theo root
        unordered_map<string, vector<string>> groups;
        for (auto& [email, name] : emailToName) {
            string root = uf.find(email);
            groups[root].push_back(email);
        }

        // Bước 3: Tạo kết quả
        vector<vector<string>> result;
        for (auto& [root, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[root]); // thêm tên vào đầu
            result.push_back(emails);
        }
        return result;
    }
};