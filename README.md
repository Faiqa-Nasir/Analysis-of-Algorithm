# Longest Common Subsequence (LCS) Algorithm

## Overview

This C++ program implements the Longest Common Subsequence (LCS) algorithm using dynamic programming. The LCS problem involves finding the longest subsequence that is common to two given strings.

## Usage

1. **Input:**
   - The program prompts the user to enter two strings.
   - Enter the first string when prompted: "Input string 1: ".
   - Enter the second string when prompted: "Input string 2: ".

2. **Output:**
   - The program calculates and displays the Longest Common Subsequence.
   - The result is printed as: "The Longest Common Subsequence is: [LCS String]".

## Code Structure

- The main logic is implemented in the `lcs` function.
- Dynamic programming is used to create a 2D array (`dp`) for storing intermediate results.
- The backtracking part reconstructs the LCS string based on the filled DP array.

