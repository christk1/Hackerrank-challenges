// https://www.hackerrank.com/challenges/ctci-ransom-note/problem
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

vector<string> split_string(string);
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    if (s == "two") {
        cout << hash_value;
    }
    return hash_value;
}

class Hash{
    int buckets;
    list<int> * table;
    public:
    Hash(int voc_size);
    int HashFunc(int key);
    void insertWord(string key);
    int searchWord(string key);
};
Hash::Hash(int voc_size){
    this->buckets = voc_size;
    this->table = new list<int>[voc_size];
}

int Hash::HashFunc(int key){
    return key % buckets;
}

void Hash::insertWord(string key){
    int index;
    int c(0);
    for(int i(0); i < key.size(); i++){
        c += key[i];
    }

    index = HashFunc(c);
    table[index].push_back(c);
}

int Hash::searchWord(string key){
    int index;
    int c(0);
    for(int i(0); i < key.size(); i++){
        c += key[i];
    }
    index = HashFunc(c);

    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == c){
            table[index].erase(i);
            return 1;
        }
    }
    return 0;
}

// Complete the checkMagazine function below.
void checkMagazine(vector<string> magazine, vector<string> note) {
    int a;
    Hash h(magazine.size());
    for(int i(0); i < magazine.size(); i++){
        h.insertWord(magazine[i]);
    }
    for(int i(0); i < note.size(); i++){
        a = h.searchWord(note[i]);
        if (a == 0) {
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}

int main()
{
    string mn_temp;
    getline(cin, mn_temp);

    vector<string> mn = split_string(mn_temp);

    int m = stoi(mn[0]);

    int n = stoi(mn[1]);

    string magazine_temp_temp;
    getline(cin, magazine_temp_temp);

    vector<string> magazine_temp = split_string(magazine_temp_temp);

    vector<string> magazine(m);

    for (int i = 0; i < m; i++) {
        string magazine_item = magazine_temp[i];

        magazine[i] = magazine_item;
    }

    string note_temp_temp;
    getline(cin, note_temp_temp);

    vector<string> note_temp = split_string(note_temp_temp);

    vector<string> note(n);

    for (int i = 0; i < n; i++) {
        string note_item = note_temp[i];

        note[i] = note_item;
    }

    checkMagazine(magazine, note);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
