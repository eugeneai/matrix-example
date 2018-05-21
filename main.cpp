#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef vector<float> vector_t;
typedef vector<vector_t> matrix_t;

class Matrix {

private:
  Matrix() = delete;

public:
  matrix_t m;
  int nrows, ncols;

  Matrix(int nrows, int ncols);
  void set(int row, int col, float value);
  void print(ostream &s);
};

class Vector {
  vector_t v;

  Vector() = delete;

public:
  int size;
  Vector(int size);
  void set(int index, float value);
  void print(ostream &s);
};


// ------------ Implementations ----------------------


Matrix::Matrix(int nrows, int ncols) {
  this->nrows = nrows;
  this->ncols = ncols;
  m = matrix_t(nrows, vector_t(ncols));
}

void Matrix::set(int row, int col, float value) {
  m[row][col] = value;
}

void Matrix::print(ostream &s){
  s << "Матрица [" << nrows << ',' << ncols << "]: " << endl;
  for (int row=0; row<nrows; row++) {
    s << row << ": ";
    for (int col=0; col<ncols; col++) {
      s << m[row][col] << ' ';
    }
    s << endl;
  }
  s << endl;
}

// Vector

Vector::Vector(int size) {
  this->size = size;
  v = vector_t(size);
}
void Vector::set(int index, float value) {
  v[index] = value;
}
void Vector::print(ostream &s) {
  s << "Вектор [" << size << "]: " ;
  for (int i=0; i<size; i++) {
    s << v[i] << ' ';
  }
  s << endl;
}



// ------------ End of Implementations --------------




int main (int __argc, char **__argv) {
  std::vector<std::string> args(__argv, __argv+__argc);

  Matrix B(2,3); // 2 rows, 3 columns
  B.set(0,0,1);
  B.set(1,1,2);
  B.set(1,2,3);
  Vector C(2);
  C.set(0,1);
  C.set(1,2);

  cout << "Выходные данные:" << endl;
  B.print(cout);
  C.print(cout);

  return 0;
}
