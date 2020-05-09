// https://www.hackerrank.com/challenges/two-strings/problem
#include <bits/stdc++.h>

using namespace std;
class Hash{
    int buckets;
    list<int> * table;
    public:
        Hash(int buckets);
        int HashFunc(int key);
        void insertSubstr(string key);
        string searchSubstr(char key);
};
Hash::Hash(int buckets){
    this->buckets = buckets;
    this->table = new list<int>[buckets];
}

int Hash::HashFunc(int key){
    return key % buckets;
}

void Hash::insertSubstr(string key){
    int index;
    for(int i(0); i < key.size(); i++){
        index = HashFunc(key[i]);
        table[index].push_back(key[i]);
    }
}

string Hash::searchSubstr(char key){
    int index;

    index = HashFunc(key);
    list<int>::iterator i;
    for(i = table[index].begin(); i != table[index].end(); i++){
        if(*i == key){
            return "YES";
        }
    }
    return "NO";
}

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    string ret;
    list<string> substrings;
    Hash h(s1.size());
    h.insertSubstr(s1);

    for(int i(0); i < s2.size(); i++){
        ret = h.searchSubstr(s2[i]);
        if (ret == "YES") {
            return ret;
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
