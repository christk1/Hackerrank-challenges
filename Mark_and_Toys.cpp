#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
void swap(int& a, int& b){
    int temp;
    temp = b;
    b = a;
    a = temp;
}

void maxHeapify(vector<int>& arr, int i, int size_)
{
    int largest, l = (2*i) + 1, r = l + 1;

    if(l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r < size_ && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, size_);
    }
}

void buildMaxHeap(vector<int>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; i--){
      maxHeapify(arr, i, arr.size());
    }
}

void heapSort(vector<int>& arr)
{
   buildMaxHeap(arr);
   int sz = arr.size();
   for(int i = arr.size() - 1; i > 0; i--)
   {
        swap(arr[0], arr[i]);
        sz--;
        maxHeapify(arr, 0, sz);
    }
}
// Complete the maximumToys function below.
int maximumToys(vector<int> prices, int k) {
    int sum(0);
    int count(0);
    heapSort(prices);

    for(int i(0); i < prices.size(); i++){
        sum += prices[i];
        if(sum > k){
            return count;
        }
        count++;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

    fout << result << "\n";

    fout.close();

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
