// https://www.hackerrank.com/challenges/luck-balance/problem

#include <bits/stdc++.h>

using namespace std;

vector <string> split_string(string);

void swap(int& a, int& b)
{
   int temp;

   temp = b;
   b    = a;
   a    = temp;
}

void maxHeapify(vector <vector <int> >& arr, int i, int size_)
{
   int largest, l = (2 * i) + 1, r = l + 1;

   if (l < size_ && arr[l][0] > arr[i][0])
   {
      largest = l;
   }
   else
   {
      largest = i;
   }

   if (r < size_ && arr[r][0] > arr[largest][0])
   {
      largest = r;
   }

   if (largest != i)
   {
      for (int j = 0; j < arr[0].size(); j++)
      {
         swap(arr[i][j], arr[largest][j]);
      }
      maxHeapify(arr, largest, size_);
   }
}

void buildMaxHeap(vector <vector <int> >& arr)
{
   for (int i = (arr.size() / 2); i >= 0; i--)
   {
      maxHeapify(arr, i, arr.size());
   }
}

void heapSort(vector <vector <int> >& arr)
{
   buildMaxHeap(arr);
   int sz = arr.size();

   for (int i = arr.size() - 1; i > 0; i--)
   {
      for (int j = 0; j < arr[i].size(); j++)
      {
         swap(arr[0][j], arr[i][j]);
      }
      sz--;
      maxHeapify(arr, 0, sz);
   }
}

// Complete the luckBalance function below.
int luckBalance(int k, vector <vector <int> > contests)
{
   heapSort(contests);
   int luck(0);

   for (int i(contests.size() - 1); i >= 0; i--)
   {
      if (contests[i][1] == 0)
      {
         luck += contests[i][0];
      }
      else if (k > 0)
      {
         luck += contests[i][0];
         k--;
      }
      else
      {
         luck -= contests[i][0];
      }
   }
   return(luck);
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   string nk_temp;

   getline(cin, nk_temp);

   vector <string> nk = split_string(nk_temp);

   int n = stoi(nk[0]);

   int k = stoi(nk[1]);

   vector <vector <int> > contests(n);

   for (int i = 0; i < n; i++)
   {
      contests[i].resize(2);

      for (int j = 0; j < 2; j++)
      {
         cin >> contests[i][j];
      }

      cin.ignore(numeric_limits <streamsize>::max(), '\n');
   }

   int result = luckBalance(k, contests);

   fout << result << "\n";

   fout.close();

   return(0);
}

vector <string> split_string(string input_string)
{
   string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char&x, const char&y) {
      return(x == y and x == ' ');
   });

   input_string.erase(new_end, input_string.end());

   while (input_string[input_string.length() - 1] == ' ')
   {
      input_string.pop_back();
   }

   vector <string> splits;
   char            delimiter = ' ';

   size_t i   = 0;
   size_t pos = input_string.find(delimiter);

   while (pos != string::npos)
   {
      splits.push_back(input_string.substr(i, pos - i));

      i   = pos + 1;
      pos = input_string.find(delimiter, i);
   }

   splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

   return(splits);
}
