class Solution {
private:
    struct Transaction {
        string name;
        int time;
        int price;
        string city;
        string original;
    };

public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<Transaction>> mpp;
        vector<string> result;

        for (string& t : transactions) {
            stringstream ss(t);
            string name, time, price, city;
            getline(ss, name, ',');
            getline(ss, time, ',');
            getline(ss, price, ',');
            getline(ss, city, ',');

            Transaction tx;
            tx.name = name;
            tx.time = stoi(time);
            tx.price = stoi(price);
            tx.city = city;
            tx.original = t;

            mpp[name].push_back(tx);
        }

        for (auto& mp : mpp) {
            auto& vec = mp.second;
            int n = vec.size();

            for (int i = 0; i < n; i++) {
                bool invalid = false;

                if (vec[i].price > 1000)
                    invalid = true;

                for (int j = 0; j < n; j++) {
                    if (i != j && abs(vec[i].time - vec[j].time) <= 60 &&
                        vec[i].city != vec[j].city) {
                        invalid = true;
                        break;
                    }
                }

                if (invalid) {
                    result.push_back(vec[i].original);
                }
            }
        }

        return result;
    }
};
