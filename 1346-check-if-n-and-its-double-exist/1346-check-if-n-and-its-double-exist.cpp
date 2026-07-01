class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i=0;i < arr.size(); i++){
            for (int j=i+1; j < arr.size(); j++ ) {
                //int val = 2 * arr[i];
                //cout << "arr[i]: " << arr[i] << " arr[j]: " << arr[j] << endl;
                if (arr[i] != 2*arr[j]) continue;
                else {
                    return true;
                }
            }
            for (int j=i-1; j>=0; j--){
                //cout << "arr[i]: " << arr[i] << " arr[j]: " << arr[j] << endl;
                if (arr[i] != 2*arr[j]) continue;
                else {
                    return true;
                }
            }
        }
        return false;
    }
};