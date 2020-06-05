#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s)
{
   int          half_len;
   vector <int> occurrences(26, 0);

   if (s.size() % 2 != 0)
   {
      return(-1);
   }
   half_len = s.size() / 2;

   for (int i(0); i < s.size(); i++)
   {
      if (i < half_len)
      {
         occurrences[s[i] - 'a']++;
      }
      else
      {
         occurrences[s[i] - 'a']--;
      }
   }
   int count(0);

   for (int i : occurrences)
   {
      count += abs(i);
   }

   return(count / 2);
}

int main()
{
   ofstream fout(getenv("OUTPUT_PATH"));

   int q;

   cin >> q;
   cin.ignore(numeric_limits <streamsize>::max(), '\n');

   for (int q_itr = 0; q_itr < q; q_itr++)
   {
      string s;
      getline(cin, s);

      int result = anagram(s);

      fout << result << "\n";
   }

   fout.close();

   return(0);
}
