// Input: Given T test cases. 

// For each test cases, k is given. k is the number of ingredients. 

// Following k, there are k lines. Each line has 3 numbers. They represent protein, fat and carbohydrate content in the kth ingredient. 

// Following these k lines, 3 lines are given. Each line has 3 numbers. They represent protein, fat and carbohydrate. For these 3 targets, we need to find out the ingredients to be added to exactly match the target. 

// Output: for the 3 lines in each test case, print space separated numbers denoting the ingredients to be added to get the exact match. 
// The ingredients must be printed in the sorted order. If there are many combinations, print the one which minimum number of ingredients.

// solution with memorization

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<pair<int, pair<int, int>>>> memo;

vector<pair<int, pair<int, int>>> findMinIngredients(vector<pair<int, pair<int, int>>> &ingredients, int target_protein, int target_fat, int target_carbohydrate, int currentIndex) {
    if (target_protein == 0 && target_fat == 0 && target_carbohydrate == 0) {
        return vector<pair<int, pair<int, int>>>{};
    }

    if (currentIndex >= ingredients.size()) {
        return vector<pair<int, pair<int, int>>>{};
    }

    string key = to_string(target_protein) + "_" + to_string(target_fat) + "_" + to_string(target_carbohydrate);
    if (memo.count(key)) {
        return memo[key];
    }

    vector<pair<int, pair<int, int>>> withCurrent;
    if (ingredients[currentIndex].first <= target_protein && ingredients[currentIndex].second.first <= target_fat && ingredients[currentIndex].second.second <= target_carbohydrate) {
        withCurrent = findMinIngredients(ingredients, target_protein - ingredients[currentIndex].first, target_fat - ingredients[currentIndex].second.first, target_carbohydrate - ingredients[currentIndex].second.second, currentIndex + 1);
        withCurrent.insert(withCurrent.begin(), ingredients[currentIndex]);
    }

    vector<pair<int, pair<int, int>>> withoutCurrent = findMinIngredients(ingredients, target_protein, target_fat, target_carbohydrate, currentIndex + 1);

    if (withCurrent.size() < withoutCurrent.size()) {
        memo[key] = withCurrent;
        return withCurrent;
    } else {
        memo[key] = withoutCurrent;
        return withoutCurrent;
    }
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int t = 0; t < num_test_cases; t++) {
        int k;
        cin >> k;

        vector<pair<int, pair<int, int>>> ingredients;
        for (int i = 0; i < k; i++) {
            int protein, fat, carbohydrate;
            cin >> protein >> fat >> carbohydrate;
            ingredients.push_back(make_pair(protein, make_pair(fat, carbohydrate)));
        }

        int target_protein, target_fat, target_carbohydrate;
        cin >> target_protein >> target_fat >> target_carbohydrate;

        memo.clear(); // Clear the memoization cache for each test case

        vector<pair<int, pair<int, int>>> result = findMinIngredients(ingredients, target_protein, target_fat, target_carbohydrate, 0);

        cout << "Ingredients: " << endl;
        for (auto ingredient : result) {
            cout << ingredient.first << " " << ingredient.second.first << " " << ingredient.second.second << endl;
        }
    }

    return 0;
}


// dp iteratieve solution

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<pair<int, pair<int, int>>> findMinIngredients(vector<pair<int, pair<int, int>>> &ingredients, int target_protein, int target_fat, int target_carbohydrate) {
    int k = ingredients.size();
    vector<vector<vector<int>>> dp(target_protein + 1, vector<vector<int>>(target_fat + 1, vector<int>(target_carbohydrate + 1, INT_MAX)));
    vector<vector<vector<bool>>> selected(target_protein + 1, vector<vector<bool>>(target_fat + 1, vector<bool>(target_carbohydrate + 1, false)));

    dp[0][0][0] = 0;

    for (int i = 0; i < k; i++) {
        for (int p = target_protein; p >= ingredients[i].first; p--) {
            for (int f = target_fat; f >= ingredients[i].second.first; f--) {
                for (int c = target_carbohydrate; c >= ingredients[i].second.second; c--) {
                    if (dp[p - ingredients[i].first][f - ingredients[i].second.first][c - ingredients[i].second.second] + 1 < dp[p][f][c]) {
                        dp[p][f][c] = dp[p - ingredients[i].first][f - ingredients[i].second.first][c - ingredients[i].second.second] + 1;
                        selected[p][f][c] = true;
                    }
                }
            }
        }
    }

    vector<pair<int, pair<int, int>>> result;
    if (dp[target_protein][target_fat][target_carbohydrate] == INT_MAX) {
        return result; // No valid combination found
    }

    int p = target_protein, f = target_fat, c = target_carbohydrate;
    while (p > 0 || f > 0 || c > 0) {
        if (selected[p][f][c]) {
            for (int i = 0; i < k; i++) {
                if (p >= ingredients[i].first && f >= ingredients[i].second.first && c >= ingredients[i].second.second && dp[p - ingredients[i].first][f - ingredients[i].second.first][c - ingredients[i].second.second] + 1 == dp[p][f][c]) {
                    result.push_back(ingredients[i]);
                    p -= ingredients[i].first;
                    f -= ingredients[i].second.first;
                    c -= ingredients[i].second.second;
                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    for (int t = 0; t < num_test_cases; t++) {
        int k;
        cin >> k;

        vector<pair<int, pair<int, int>>> ingredients;
        for (int i = 0; i < k; i++) {
            int protein, fat, carbohydrate;
            cin >> protein >> fat >> carbohydrate;
            ingredients.push_back(make_pair(protein, make_pair(fat, carbohydrate)));
        }

        int target_protein, target_fat, target_carbohydrate;
        cin >> target_protein >> target_fat >> target_carbohydrate;

         vector<pair<int, pair<int, int>>> result = findMinIngredients(ingredients, target_protein, target_fat, target_carbohydrate, 0);

        cout << "Ingredients: " << endl;
        for (auto ingredient : result) {
            cout << ingredient.first << " " << ingredient.second.first << " " << ingredient.second.second << endl;
        }
    }

    return 0;
}
