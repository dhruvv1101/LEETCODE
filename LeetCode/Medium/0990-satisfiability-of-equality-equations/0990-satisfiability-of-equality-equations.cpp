class Solution {
public:
    vector<int> parent, rank;

    void makeset(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unions(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        makeset(26);
        for(string &s:equations){
            if(s[1]=='='){
                unions(s[0]-'a',s[3]-'a');
            }
        }
        for(string &s:equations){
            if(s[1]=='!'){
                if(find(s[0]-'a')==find(s[3]-'a')){
                    return false;
                }
            }
        }
        return true;
    }
};