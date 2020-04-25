#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

class ChessBoardArray {
protected:

int *data;
int base;
unsigned num;
unsigned loc(int i, int j) const throw(logic_error){
  int di=i-base, dj=j-base;  
      if (di<0 || dj<0 || di>=num || dj>=num || (di+dj)%2!=0) throw logic_error("wrong index");
    return ((di+1)/2)*((num+1)/2)+(di/2)*(num/2)+dj/2;

}

class Row {

ChessBoardArray &board;
int row;

  public:
  Row(ChessBoardArray &a, int i): board(a){
    
    row = i;
  }
  int & operator [] (int i) const{
    return board.select(row, i);
  }
};

class ConstRow {

const ChessBoardArray &board;
int row;

public:
  ConstRow(const ChessBoardArray &a, int i): board(a) {
    
    row = i;
  }
  int operator [] (int i) const{
    return board.select(row, i);
  }
};

public:
 ChessBoardArray(unsigned size = 0, unsigned base = 0)
 : num(size), base(0), data(new int[(num*num+1)/2]){
   for (int i = 0 ; i < (num*num+1)/2 ; i++ ) data[i] = 0;
 }
 ChessBoardArray(const ChessBoardArray &a){
   num = a.num;
   base = a.base;
   data = new int[(num*num+1)/2];
   for (int i = 0; i < (num*num+1)/2; i++) data[i] = a.data[i];
 }

 ~ChessBoardArray()
 {
   delete [] data;
 }

 ChessBoardArray & operator = (const ChessBoardArray &a){
   delete [] data;
   num = a.num;
   base = a.base;
   data = new int[(num*num+1)/2];
   for (int i = 0; i < (num*num+1)/2; i++) data[i] = a.data[i];
   return *this;
 }

 int & select(int i, int j){
   return data[loc(i,j)];
 }
 const int select(int i, int j) const{
   return data[loc(i,j)];
 }
 const Row operator [] (int i) {
   return Row(*this, i);
 }
 const ConstRow operator [] (int i) const{
   return ConstRow(*this, i);
 }

 friend ostream & operator << (ostream &out, const ChessBoardArray &a){
   for (int i = 0; i < a.num ; i++){
    for (int j = 0; j < a.num ; j++){
    if ((i+j)%2==0){
      out << setw(4) << a[i+a.base][j+a.base];
    }
    else out<<setw(4)<<0;
    }
    out<<endl;
   }
   return out;
 }
};

int main(){
  return 0;
}