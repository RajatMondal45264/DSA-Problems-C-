class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // Available Severs 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> available;

        //Busy Servers 
        priority_queue<tuple<long long ,int,int>,vector<tuple<long long ,int,int>>,greater<tuple<long long,int,int>>>busy;

        vector<int>ans(m);

        // Initially all Servers are avilable 
        for(int i = 0; i< n; i++)
        {
            available.push({servers[i],i});
        }

        long long time = 0;

        //Process tasks one by one 
        for(int i = 0; i< m; i++)
        {
            //task i arrives at time i
            time = max(time , (long long)i);

            //Release servers that have completed their tasks
            while(!busy.empty() && get<0>(busy.top()) <= time)
            {
                auto [freeTime,weight,index] = busy.top();
                busy.pop();

                available.push({weight,index});
            }

            //if no servers is available , wait 
            if(available.empty())
            {
                time = get<0>(busy.top());

                //release all servers that become free at this time
                while(!busy.empty() && get<0>(busy.top()) <= time)
                {
                    auto [freeTime,weight,index] = busy.top();
                    busy.pop();

                    available.push({weight,index});
                }
            }

            // select the best available server 
            auto [weight,index] = available.top();
            available.pop();

            //store the selected server index 
            ans[i] = index;

            //calculate when this server will become free 
            long long freeTime = time + tasks[i];

            //move the server into busy heap
            busy.push({freeTime,weight,index});

        }

        return ans;

    }
};