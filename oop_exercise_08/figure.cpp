#include "figure.h"

std::ostream& operator<< (std::ostream& os, const figure::Figure& f) {
  f.print(os);
  return os;
}
