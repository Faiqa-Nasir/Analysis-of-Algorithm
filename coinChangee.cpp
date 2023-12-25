#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

bool possibleWithGreedy(vector<int>& arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int length = arr.size();
    int count = 0;
    int value = arr[length - 1];
    for (auto item : arr) {

        if ((int)fmod(item, value) == 0)
            count++;
    }

    return count == length;
}

int calculateChangeGreedy(vector<int>& coinValues, vector<string>& coinNames, int numOfCoins, float targetAmount)
{

    int count = 0;
    vector<pair<int, int>> coinsUsed;
    for (int i = 0; i < numOfCoins; i++)
    {
        if (targetAmount >= coinValues[i])
        {
            int currentCount = targetAmount / coinValues[i];
            count += currentCount;
            targetAmount -= currentCount * coinValues[i];
            coinsUsed.push_back({ currentCount,i });
        }
    }
    if (targetAmount != 0)
        return -1;
    for (auto item : coinsUsed)
        cout << item.first << " " << coinNames[item.second] << endl;
    return count;
}
int calculateChangeDP(vector<int>& coins, int T, vector<string>& coinNames) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    reverse(coins.begin(), coins.end());
    reverse(coinNames.begin(), coinNames.end());
    for (int i = 0; i <= T; i++) {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            int notTake = dp[ind - 1][target];

            int take = 1e9;
            if (coins[ind] <= target && dp[ind][target - coins[ind]] != 1e9)
                take = 1 + dp[ind][target - coins[ind]];

            dp[ind][target] = min(notTake, take);
        }
    }

    int ans = dp[n - 1][T];

    if (ans >= 1e9)
        return -1;

    vector<int> coinCounts(n, 0);
    int remainingAmount = T;
    for (int i = n - 1; i >= 0; i--) {
        while (remainingAmount >= coins[i] && dp[i][remainingAmount] == dp[i][remainingAmount - coins[i]] + 1) {
            coinCounts[i]++;
            remainingAmount -= coins[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (coinCounts[i] != 0) {
            cout << coinCounts[i] << " " << coinNames[i];
            if (coinCounts[i] > 1)
                cout << "s";
            cout << endl;
        }
    }

    return ans;
}


    int main() {
        ifstream inputFile;
        inputFile.open("Coins.txt");

        if (inputFile) {
            string currencyName, symbol, coinName;
            int numOfCoins;
            float targetAmount;
            inputFile >> currencyName;
            inputFile >> symbol;
            inputFile >> numOfCoins;
            vector<int> coinValues;
            vector<string> coinNames;

            for (int i = 0; i < numOfCoins; i++) {
                inputFile >> coinName;
                float value;
                inputFile >> value;
                coinValues.push_back(value);
                coinNames.push_back(coinName);
                inputFile >> coinName;
            }
            cout << "Enter the value for which coin-change is required in " << currencyName << " : ";
            cin >> targetAmount;
            int minCoins = 0;
            if (!possibleWithGreedy(coinValues)) {
                minCoins = calculateChangeDP(coinValues, targetAmount, coinNames);
            }
            else {
                minCoins = calculateChangeGreedy(coinValues, coinNames, numOfCoins, targetAmount);
            }

            if (minCoins == -1) {
                cout << "No solution exists." << endl;
            }
            else {
                cout << "\nMinimum number of coins needed: " << minCoins << endl;
            }
        }

        return 0;
    }
