class Solution {
public:
    int dfs(int box,vector<int>& s, vector<int>& can, vector<vector<int>>& keys, vector<vector<int>>& cb,unordered_set<int>&vis,unordered_set<int>&fb){
        if(vis.count(box)){
            return 0;//checks if prev vis then candy count is 0 as we already took
        }
        if(!s[box]){//if status is 0 we cant take candies so push in found boxes
            fb.insert(box);//foundboxes
            return 0;//candy count zero initial visit
        }
        vis.insert(box);//insert in visited array
        int cancol=can[box];//candy count non zero so inc candiescount by candies[box];
        for(auto &inbox:cb[box]){//iterate in collected boxes of current box
            cancol+=dfs(inbox,s,can,keys,cb,vis,fb);//run dfs for it
        }
        for(auto &bkey:keys[box]){//checks if any keys found and they are of any found box till now
            s[bkey]=1;//marks status of box as 1
            if(fb.count(bkey)){//checks if box is found already 
                cancol+=dfs(bkey,s,can,keys,cb,vis,fb);//inc candy collected count using dfs again
            }
        }
        return cancol;//returns total candies collected till now;
    }
    int maxCandies(vector<int>& s, vector<int>& can, vector<vector<int>>& keys, vector<vector<int>>& cb, vector<int>& ib) {
        int candies=0;
        unordered_set<int>vis,fb;
        //done using simple dfs
        for(int &box:ib){
            candies+=dfs(box,s,can,keys,cb,vis,fb);//count candies by visiting every box inside if status 1;
        }
        return candies;
    }
};