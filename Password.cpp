#include "Password.h"
#include <cctype>
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  if (phrase.length() == 0) return 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }

  return repetition;
}

bool Password::contains_unicode(string pass)
{
    for (unsigned char c : pass) {
        if (c > 127) return true;
    }

    return false;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass)
{
    bool hasLower = false;
    bool hasUpper = false;

    for (char c : pass) {
        if (std::islower(static_cast<unsigned char>(c))) hasLower = true;
        if (std::isupper(static_cast<unsigned char>(c))) hasUpper = true;
    }

    return hasUpper && hasLower;
}
