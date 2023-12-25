# Coin Change Problem Solver

This C++ program solves the coin change problem using both a greedy algorithm and dynamic programming. The problem involves finding the minimum number of coins needed to make change for a given target amount.

## Features

- **Greedy Algorithm:** The program checks if a greedy solution is possible for the given set of coin denominations and calculates the minimum number of coins using a greedy approach if applicable.

- **Dynamic Programming:** If the greedy solution is not possible, the program utilizes dynamic programming to find the optimal solution. It fills a dynamic programming table to calculate the minimum number of coins needed for various target amounts.

## Input

The program reads input from a file named "Coins.txt." The file format includes information about the currency, symbol, number of coins, coin names, and their values. Additionally, the user is prompted to enter the target value for which coin change is required.

## Output

The program outputs the minimum number of coins needed to make change for the target amount. If a solution exists, it also prints the individual coin counts and names.

