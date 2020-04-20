#include <iostream>
#include <iomanip>

class ChessBoardArray {
protected:

T *data;
int baseRow, baseCol;
unsigned numRows, numCols;
unsigned loc(inti, intj) constthrow(out_of_range);

class Row {
  public:
  Row(ChessBoardArray &a, int i);
  int & operator [] (int i) const;
};

class ConstRow {
public:
  ConstRow(const ChessBoardArray &a, int i);
  int operator [] (int i) const;
};

public:
 ChessBoardArray(unsigned size = 0, unsigned base = 0);
 ChessBoardArray(const ChessBoardArray &a);
 ~ChessBoardArray();

 ChessBoardArray & operator = (const ChessBoardArray &a); {

 int & select(int i, int j);
 int select(int i, int j) const;
 const Row operator [] (int i);
 const ConstRow operator [] (int i) const;

 friend ostream & operator << (ostream &out, const ChessBoardArray &a);
};
