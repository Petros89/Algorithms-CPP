
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class PasswordValidation
{
public:

   static bool strongPassword(string password)
   {
      if (password.size() < 12)
         return false;

      size_t ucc = 0;
      size_t lcc = 0;
      size_t dc  = 0;

      for (auto i : password)
      {
         if ('a' <= i && i <= 'z')
            ++lcc;
         else if ('A' <= i && i <= 'Z')
            ++ucc;
         else if (isdigit(i))
            ++dc;
      }

      if (ucc < 1 || lcc < 1 || dc < 1)
         return false;

      size_t x = 0;
      while (x < password.size() && isdigit(password[x])) ++x;

      size_t y = password.size() - 1;
      while (y > 0 && isdigit(password[y])) y -= 1;

      if (x >= y)
         return false;

      return ((((y - x) + 1) - (ucc + lcc))) > 0;
   }
};




int main(){

    string pass = "Abch3fc1Tdsz";

    char c;
    int r;

    srand (time(NULL));    // initialize the random number generator
    for (int i=0; i<10; i++)
    {    r = rand() % 10;   // generate a random number
          c = 'a' + r;            // Convert to a character from a-z
          cout << c;
    }
    cout << "\n";



    cout << boolalpha << PasswordValidation::strongPassword(pass) << "\n";

    return EXIT_SUCCESS;
}
