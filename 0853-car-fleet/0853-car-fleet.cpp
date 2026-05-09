class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars; 
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Sắp xếp theo vị trí giảm dần
        sort(cars.begin(), cars.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        int fleets = 0;
        double curTime = 0.0;
        for (auto &car : cars) {
            if (car.second > curTime) {
                fleets++;
                curTime = car.second; // fleet leader mới
            }
            // nếu car.second <= curTime thì xe này nhập vào fleet hiện tại
        }
        return fleets;
    }
};