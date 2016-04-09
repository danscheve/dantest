 #include <map>
 #include <set>
 #include <list>
 #include <cmath>
 #include <ctime>
 #include <climits>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <cstdio>
 #include <limits>
 #include <vector>
 #include <cstdlib>
 #include <fstream>
 #include <numeric>
 #include <sstream>
 #include <iostream>
 #include <algorithm>
#include <cctype>
#include <string>
#include <string.h>
using namespace std;
//  Complete the function below.
//  write a function that provides a ranked (hi to lo) list of courses (courseIDs) for a given user
//Test Data below:
/*
 * User    Number  Courses         Friends
   Dan     1       100,200,300     Julie, Kristen, Laurel
   Julie   2       200,400         Dan, Kristen, Laurel
   Kristin 3       100,200,400     Laurel, Dan
   Laurel  4       100,300         Julie, Kristen


getDirectFriendsForUser (strings that represent direct friends)
getAtttendedCoursesForUser - list of course IDs for that user ordered by attendance time.  First entry oldest.

recommend course such that:
 Only courses not yet taken are proposed.
 Recommend only to Direct friends of user.

   1) Each user's list of friends
   2) Courses to recommend to each user

*/
vector<string> getDirectFriendsForUser(string user);
vector<string> getDirectFriendsForUser(string user)
{
  vector<string> s(3);
  if (user.compare("Dan") ==0)
  {
    s[0] = "Julie";
    s[1] = "Kristin";
    s[2] = "Laurel";
  }
  else if (user.compare("Julie") ==0)
  {
    s[0] = "Dan";
    s[1] = "Kristin";
    s[2] = "Laurel";
  }
  else if (user.compare("Kristin") ==0)
  {
    s[0] = "Laurel";
    s[1] = "Dan";
    s[2] = "";
  }
  else if (user.compare("Laurel") ==0)
  {
    s[0] = "Julie";
    s[1] = "Kristin";
    s[2] = "";
  }
  else
  {
    s[0] = "";
    s[1] = "";
    s[2] = "";
  }
  return s;  
}
vector<string> (getRankedCourses(string user));
vector<string> (getRankedCourses(string user))
{
  vector<string> s(4);
  if (user.compare("Dan") ==0)
  {
    s[0] = "100";
    s[1] = "200";
    s[2] = "300";
    s[3] = "";
  }
  else if (user.compare("Julie") ==0)
  {
    s[0] = "200";
    s[1] = "400";
    s[2] = "";
    s[3] = "";
  }
  else if (user.compare("Kristin") ==0)
  {
    s[0] = "100";
    s[1] = "200";
    s[2] = "400";
    s[3] = "";
  }
  else if (user.compare("Laurel") ==0)
  {
    s[0] = "100";
    s[1] = "300";
    s[2] = "";
    s[3] = "";
  }
  else
  {
    s[0] = "";
    s[1] = "";
    s[2] = "";
    s[3] = "";
  }
  return s; 
}

main()
{
  int i,j,k;
  vector<string> UserFriends;
  vector<string> UserCourses;
  string user1[] = {"Dan", "Julie", "Kristin", "Laurel"};
  string courses1[] = {"100", "200", "300", "400"};
  for (i=0; i<4; ++i)
  {
    UserFriends =  getDirectFriendsForUser(user1[i]);
    cout <<"Friends of " << user1[i] <<endl;
    for (j=0; j<3; ++j)
    {
      if (UserFriends[j].length())
        cout << UserFriends[j] << endl;
    }
    cout <<"Courses to recommend for " << user1[i] <<endl;
    UserCourses =  getRankedCourses(user1[i]);
    int found;
    for (j=0; j<4; ++j)
    {
      found = 0;
      for (k=0; k<4; ++k)
      {
        if (courses1[j].compare(UserCourses[k]) == 0)
        {
          //cout << "matched " << courses << " with "  << usercourses << endl;
          found = 1;
        }
        if (found) break;
      }
      if (!found)  
        cout << courses1[j] << endl;
    }
    cout << endl;
  }
}
