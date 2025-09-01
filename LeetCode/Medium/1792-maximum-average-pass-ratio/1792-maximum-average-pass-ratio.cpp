class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i=0;i<classes.size();i++){
            int n=classes[i][0];
            int d=classes[i][1];
            double c=(double)(n+1)/(d+1)-(double)n/d;
            pq.push({c,{n,d}});
        }
        //made the pq for max change with num and deno values
        for(int i=0;i<extraStudents;i++){
            auto [c,p]=pq.top();
            pq.pop();
            int n=p.first;
            int d=p.second;
            n++;
            d++;
            //update the top of pq values and push them again in pq for next iteration
            double nc=(double)(n+1)/(d+1)-(double)n/d;
            pq.push({nc,{n,d}});
        }
        //calculate passratio
        double passratio=0;
        while(!pq.empty()){
            auto [a,b]=pq.top();
            pq.pop();
            int n=b.first;
            int d=b.second;
            passratio+=(double)n/d;
        }
        return passratio/classes.size();
        
    }
};