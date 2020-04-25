#include <iostream>
#include <iomanip>

class ChessBoardArray {
protected:

T *data;
int base;
unsigned num;
unsigned loc(int i, int j) const throw(out_of_range){
  int di=i-base, dj=j-base;  
      if (di<0 || dj<0 || di>=n || dj>=n || (di+dj)%2!=0) throw out_of_range("wrong index");
    return di*(n+1)/2 + dj/2;

}

class Row {

ChessBoardArray &board;
int row;

  public:
  Row(ChessBoardArray &a, int i):
  board(a); row(i); {}
  int & operator [] (int i) const{
    return board.select(row, i);
  }
};

class ConstRow {

const ChessBoardArray &board;
int row;

public:
  ConstRow(const ChessBoardArray &a, int i):
  board(a); row(i); {}
  int operator [] (int i) const{
    return board.select(row, i);
  }
};

public:
 ChessBoardArray(unsigned size = 0, unsigned base = 0)
 : n(size), base(0), data(new int[(n*n+1)/2]){
   for (int i = 0 ; i < (n*n+1)/2 ; i++ ) data[i] = 0;
 }
 ChessBoardArray(const ChessBoardArray &a){
   n(a.n);
   base(a.base);
   data(new int [(n*n+1)/2]);
   for (int i = 0; i < (n*n+1)/2; i++) data[i] = a.data[i];
 }

 ~ChessBoardArray();
 {
   delete [] data;
 }

 ChessBoardArray & operator = (const ChessBoardArray &a){
   delete [] data;
   n(a.n);
   base(a.base);
   data(new int [(n*n+1)/2]);
   for (int i = 0; i < (n*n+1)/2; i++) data[i] = a.data[i];
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
   for (int i = 0; i < n ; i++){
    for (int j = 0; j < n ; j++)
    if ((i+j)%2==0){
      out << setw(4) << a[i+a.base][j+a.base];
    }
    else out<<setw(4)<<0;
    out<<endl;
   }
   return out;
 }
};
