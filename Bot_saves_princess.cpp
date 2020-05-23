// https://www.hackerrank.com/challenges/saveprincess/problem

#include <iostream>
#include <vector>
using namespace std;

void displayPathtoPrincess(int n, vector <string> grid)
{
   //your logic here
   int f, s;

   if (grid[0][0] == 'p')
   {
      f = 0;
      s = 0;
   }
   else if (grid[0][n - 1] == 'p')
   {
      f = 0;
      s = n - 1;
   }
   else if (grid[n - 1][0] == 'p')
   {
      f = n - 1;
      s = 0;
   }
   else if (grid[n - 1][n - 1] == 'p')
   {
      f = n - 1;
      s = n - 1;
   }
   else
   {
      return;
   }

   int centr;

   centr = n / 2 + 1;
   if (centr > f)
   {
      for (int i(0); i < centr - 1; i++)
      {
         cout << "UP" << endl;
      }
   }
   else
   {
      for (int i(0); i < centr - 1; i++)
      {
         cout << "DOWN" << endl;
      }
   }
   if (centr > s)
   {
      for (int i(0); i < centr - 1; i++)
      {
         cout << "LEFT" << endl;
      }
   }
   else
   {
      for (int i(0); i < centr - 1; i++)
      {
         cout << "RIGHT" << endl;
      }
   }
}

int main(void)
{
   int             m;
   vector <string> grid;

   cin >> m;

   for (int i = 0; i < m; i++)
   {
      string s; cin >> s;
      grid.push_back(s);
   }

   displayPathtoPrincess(m, grid);

   return(0);
}
