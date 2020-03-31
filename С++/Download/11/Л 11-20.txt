// dothis.cpp
// как указатель this ссылается на данные
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class what
  {
  private:
    int alpha;
  public:
    void tester()
      {
      this->alpha = 11;    //то же,что alpha = 11;
      cout << this->alpha; //то же, что cout <<
                           //alpha;
      }
  };
///////////////////////////////////////////////////////////
int main()
  {
  what w;
  w.tester();
  cout << endl;
  return 0;
  }


