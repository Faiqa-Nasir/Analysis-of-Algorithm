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
void displayUsedDenominations(const vector<int>& counts, const vector<string>& names) {
    cout << "Denominations used are:" << endl;
    for (size_t i = 0; i < counts.size(); i++) {
        if (counts[i] > 0) {
            cout << counts[i] << " " << names[i];
            if (counts[i] > 1)
                cout << "s";
            cout << endl;
        }
    }
}

int calculateChangeDP(const vector<int>& denominations, int targetAmount, const vector<string>& denominationNames) {
    vector<int> dp(targetAmount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= targetAmount; i++) {
        for (int den : denominations) {
            if (i >= den && dp[i - den] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - den]);
            }
        }
    }

    if (dp[targetAmount] == INT_MAX)
        return -1;

    vector<int> coinsUsed(denominations.size(), 0);
    int amountRemaining = targetAmount;
    while (amountRemaining > 0) {
        for (size_t i = 0; i < denominations.size(); i++) {
            if (amountRemaining >= denominations[i] && dp[amountRemaining] == 1 + dp[amountRemaining - denominations[i]]) {
                coinsUsed[i]++;
                amountRemaining -= denominations[i];
                break;
            }
        }
    }

    displayUsedDenominations(coinsUsed, denominationNames);
    return dp[targetAmount];
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
