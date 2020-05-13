// https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem

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
// Complete the minimumAbsoluteDifference function below.
int minimumAbsoluteDifference(vector<int> arr) {
    int min, num;
    heapSort(arr);
    min = abs(arr[0] - arr[1]);
    for(int i(1); i < arr.size() - 1; i++){
        num = abs(arr[i] - arr[i + 1]);
        if(num < min){
            min = num;
        }
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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
