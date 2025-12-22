class Solution {
public:
    vector<int> hours = {8, 4, 2, 1};
    vector<int> minutes = {32, 16, 8, 4, 2, 1};
    vector<string> result;
    void helper(int i, int turnedOn, int hour, int minute) {
        if (hour > 11 || minute > 59)
            return;

        if (turnedOn == 0) {
            string time = to_string(hour) + ':';
            if (minute < 10) {
                time += '0';
            }
            time += to_string(minute);
            result.push_back(time);
            return;
        }
        if (i == 10) {
            return;
        }
        if (i < 4) {
            helper(i + 1, turnedOn - 1, hour + hours[i], minute);
        } else {
            helper(i + 1, turnedOn - 1, hour, minute + minutes[i - 4]);
        }
        helper(i + 1, turnedOn, hour, minute);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        helper(0, turnedOn, 0, 0);
        return result;
    }
};