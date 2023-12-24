# Longest Common Subsequence (LCS) Algorithm
#  Recursive Solution

This program finds the Longest Common Subsequence (LCS) of two given strings using a recursive approach.

## Problem Statement

Given two strings, the program aims to find the LCS, which is the longest sequence of characters that appear in the same order in both strings.

## Solution Overview

The provided solution uses a recursive function `recursionLCS` to find the LCS of two strings. The main function takes user input for two strings, calculates the length of the LCS, and prints both the LCS and its length.

## Code Structure

- **recursionLCS Function:**
  - Inputs: Two strings (`str1` and `str2`) and their sizes (`size1` and `size2`).
  - Outputs: Returns the length of the LCS and updates the `ans` string with the LCS.
  - Base Case: If either of the string sizes is zero, return 0.
  - Recursive Cases:
    - If the last characters of both strings match, include the character in the LCS.
    - Recursively call for both strings excluding their last characters.
    - Return the maximum length obtained from the recursive calls.
    
- **Main Function:**
  - Takes user input for two strings.
  - Calculates the length of the LCS using the `recursionLCS` function.
  - Prints the LCS and its length.


## How to Use

1. Compile the code using a C++ compiler.
2. Run the executable.
3. Enter the first string when prompted.
4. Enter the second string when prompted.
5. The program will output the Longest Common Subsequence and its length.


# DP SOLUTION Overview

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

