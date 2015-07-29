// Final Project Milestone 3 
// Good Tester program
// File	GoodTester.cpp
// Version 1.0
// Date	2015/07/28
// Author	Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2015/04/03		       Preliminary release
/////////////////////////////////////////////////////////////////

#include "Good.h"
#define TAB '\t'
#include <iomanip>
using namespace std;
namespace oop244{
  class SGood :public Good{
  public:
    SGood() :Good("", "", 0, 0){}
    SGood(const SGood& SG) :Good(SG){};
    virtual std::fstream& store(std::fstream& file)const{
      file.open("ms3.txt", ios::out);
      file << upc() << TAB << name() << TAB << quantity() << TAB << qtyNeeded() << TAB
        << int(taxed()) << TAB << price() << endl;
      file.close();
      return file;
    }
    virtual std::fstream& load(std::fstream& file){
      file.open("ms3.txt", ios::in);
      char buf[2000];
      double dbuf;
      int ibuf;
      file >> buf;
      upc(buf);
      file >> buf;
      name(buf);
      file >> ibuf;
      quantity(ibuf);
      file >> ibuf;
      qtyNeeded(ibuf);
      file >> ibuf;
      taxed(bool(ibuf));
      file >> dbuf;
      price(dbuf);
      file.close();
      return file;
    }
    virtual std::ostream& display(std::ostream& os, bool linear)const{
      return os << upc() << ": " << name() << endl
        << quantity() << "<OnHand --- Needed>" << qtyNeeded() << endl
        << fixed << setprecision(2) << cost();
    }
    virtual std::istream& conInput(std::istream& is){
      char buf[2000];
      double dbuf;
      int ibuf;
      cout << "upc: ";
      is >> buf;
      upc(buf);
      cout << "name (no spaces): ";
      is >> buf;
      name(buf);
      cout << "qty: ";
      is >> ibuf;
      quantity(ibuf);
      cout << "qty Needed: ";
      is >> ibuf;
      qtyNeeded(ibuf);
      cout << "is taxed? (1/0): ";
      is >> ibuf;
      taxed(bool(ibuf));
      cout << "price: ";
      is >> dbuf;
      price(dbuf);
      return is;
    }
  };
}

using namespace oop244;
int main(){
  double res, val = 0.0;
  fstream F;
  SGood Cn, Ld, Gd;
  cout << "Enter Good info: " << endl;
  cin >> Cn;
  SGood Cpy = Cn;
  Cn.store(F);
  Ld.load(F);
  cout << "Ld: (store, load)----------" << endl;
  cout << Ld << endl <<endl;
  cout << "Cn: ----------" << endl;
  cout << Cn << endl << endl;
  cout << "Cpy(Cn): ----------" << endl;
  cout << Cpy << endl << endl;
  cout << "Gd=Ld; op=----------" << endl;
  Gd = Ld;
  cout << Gd << endl << endl;;
  cout << "Operator ==----------" << endl;
  cout << "op== is " << ((Ld == "123") ? "OK" : "NOT OK") << endl <<endl;
  cout << "op+=: qty += 20----------" << endl;
  Gd += 7;
  cout << Gd << endl << endl;
  cout << "op+=double: ----------" << endl;
  res = val += Gd;
  cout << res << "=" << val << endl << endl;
  return 0;
}