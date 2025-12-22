class Solution {
public:
    vector<int> hours = {8, 4, 2, 1};
    vector<int> minutes = {32, 16, 8, 4, 2, 1};
    vector<string> result;
    void helper(int idx, int turnedOn, int hour, int minute) {
        if (hour > 11 || minute > 59) return;
        if (turnedOn == 0) {
            string time = to_string(hour) + ":";
            if (minute < 10) time += "0";
            time += to_string(minute);
            result.push_back(time);
            return;
        }

        if (idx == 10) return;

        if (idx < 4)
            helper(idx + 1, turnedOn - 1, hour + hours[idx], minute);
        else
            helper(idx + 1, turnedOn - 1, hour, minute + minutes[idx - 4]);

        helper(idx + 1, turnedOn, hour, minute);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        helper(0, turnedOn, 0, 0);
        return result;
    }
};
