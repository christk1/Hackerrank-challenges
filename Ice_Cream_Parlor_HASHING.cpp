// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem

#include <bits/stdc++.h>

using namespace std;

vector <string> split_string(string);
class Hash {
   int buckets;
   list <int> *table;
public:
   Hash(int backets);
   void insertVal(int key);
   bool searchVal(int key);
   int HashFunc(int key);
};

Hash::Hash(int buckets)
{
   this->buckets = buckets;
   this->table   = new list <int>[buckets];
}

int Hash::HashFunc(int key)
{
   return(key % buckets);
}

void Hash::insertVal(int key)
{
   int index;

   index = HashFunc(key);
   table[index].push_back(key);
}

bool Hash::searchVal(int key)
{
   int index;

   index = HashFunc(key);
   list <int>::iterator i;

   for (i = table[index].begin(); i != table[index].end(); i++)
   {
      if (*i == key)
      {
         return(true);
      }
   }
   return(false);
}

// Complete the whatFlavors function below.
void whatFlavors(vector <int> cost, int money)
{
   Hash h(cost.size());
   int  Sunny, Johnny;
   bool ret;

   for (int i(0); i < cost.size(); i++)
   {
      h.insertVal(cost[i]);
   }

   for (int i(0); i < cost.size(); i++)
   {
      Sunny  = cost[i];
      Johnny = money - Sunny;
      ret    = h.searchVal(Johnny);
      if (ret)
      {
         for (int j(0); j < cost.size(); j++)
         {
            if (cost[j] == Johnny && j != i)
            {
               cout << i + 1 << ' ' << j + 1 << endl;
               return;
            }
         }
      }
   }
}

int main()
{
   int t;

   cin >> t;
   cin.ignore(numeric_limits <streamsize>::max(), '\n');

   for (int t_itr = 0; t_itr < t; t_itr++)
   {
      int money;
      cin >> money;
      cin.ignore(numeric_limits <streamsize>::max(), '\n');

      int n;
      cin >> n;
      cin.ignore(numeric_limits <streamsize>::max(), '\n');

      string cost_temp_temp;
      getline(cin, cost_temp_temp);

      vector <string> cost_temp = split_string(cost_temp_temp);

      vector <int> cost(n);

      for (int i = 0; i < n; i++)
      {
         int cost_item = stoi(cost_temp[i]);

         cost[i] = cost_item;
      }

      whatFlavors(cost, money);
   }

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
