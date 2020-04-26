#include <iomanip>  
#include <iostream>  
#include <stdexcept>  
  
using namespace std;  
  
class ChessBoardArray {  
protected:  
    class Row {  
    public:  
        Row(ChessBoardArray &a, int i) : board(a), row(i) {}  
  
        int & operator [] (int i) const {  
            return board.select(row, i);  
        }  
  
    private:  
        ChessBoardArray &board;  
        int row;  
    };  
  
    class ConstRow {  
    public:  
        ConstRow(const ChessBoardArray &a, int i) : board(a), row(i) {}  
        int operator [] (int i) const {  
            return board.select(row, i);  
        }  
    private:  
        const ChessBoardArray &board;  
        int row;  
    };  
  
public:  
    ChessBoardArray(unsigned int siz = 0, unsigned int base = 0) {  
        data_size = siz * siz / 2 + ((siz % 2) ? 1 : 0);  
  
        data = new int[data_size];  
  
        mbase = base;  
  
        size = siz;  
    }  
  
    ChessBoardArray(const ChessBoardArray &a):  
        data_size(a.data_size),  
        data(new int[a.data_size]),  
        mbase(a.mbase),  
        size(a.size) {  
        for (int i = 0; i < data_size; i++)  
            data[i] = a.data[i];  
    }  
  
    ~ChessBoardArray() { delete[] data; }  
  
    ChessBoardArray & operator = (const ChessBoardArray &a) {  
        delete [] data;  
        data_size = a.data_size;  
        size = a.size;  
        mbase = a.mbase;  
        data = new int[data_size];  
        for (int i = 0; i < a.data_size; i++) data[i] = a.data[i];  
        return *this;  
    }  
  
    int & select(int i, int j) {  
        return data[loc(i, j)];  
    }  
  
    int select(int i, int j) const {  
        return data[loc(i, j)];  
    }  
  
    const Row operator [](int i) {  
        return Row(*this, i);  
    }  
    const ConstRow operator [](int i) const {  
        return ConstRow(*this, i);  
    }  
  
    friend ostream & operator <<(ostream &out, const ChessBoardArray &a) {  
        for (int k = 0; k < a.data_size; k++) {}  
        int i = 0;  
        for (int row = 0; row < a.size; row++) {  
            if (row % 2) {  
                for (int j = 0; j < a.size / 2; j++) {  
                    out << setw(4) << 0 << setw(4) << a.data[i++];  
                }  
                if (a.size % 2)  
                    out << setw(4) << 0;  
            }  
            else {  
                for (int j = 0; j < a.size / 2; j++) {  
                    out << setw(4) << a.data[i++] << setw(4) << 0;  
                }  
                if (a.size % 2)  
                    out << setw(4) << a.data[i++];  
            }  
            out << endl;  
        }  
        return out;  
    }  
  
private:  
    int *data;  
    int data_size;  
    int size;  
    int mbase;  
  
    unsigned int loc(int i, int j) const throw(out_of_range) {  
        i -= mbase - 1;  
        j -= mbase - 1;  
        int s = i + j;  
        if (i > size || i < 1 || j > size || j < 1)  
            throw out_of_range("fix i and j");  
        else if (s % 2)  
            throw out_of_range("black cell");  
        else {  
            s = (size) / 2 * (i - 1) + j / 2 + j % 2 - 1 + size % 2 * i / 2;  
            return s;  
        }  
    }  
};
 int main(){return 0;}