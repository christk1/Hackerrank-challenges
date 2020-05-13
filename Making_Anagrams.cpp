// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int count(0);
    vector<int> occurrences(26, 0);
    for(int c : a){
        occurrences[c - 'a']++;
    }
    for(int c : b){
        occurrences[c - 'a']--;
    }
    for(int c : occurrences){
        count += abs(c);
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
