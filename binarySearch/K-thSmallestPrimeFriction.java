//link: https://leetcode.com/problems/k-th-smallest-prime-fraction/


//Explanation: since array is in sorted order and i < j means numeraor is always less than the denominator
// so value of friction always like between 0 to 1
//we have a search space between 0 to 1 now for every mid we count the number of frictions less than
// that mid and we maintain the value of largest friction while counting for ans because we need to return the kth smallest friction.
// if count == k then return the ans;
// if count > k then make right = mid else make left = mid;

