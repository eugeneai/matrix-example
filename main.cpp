#include <vector>
#include <iostream>
#include <string>
#include <cassert>

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

  // Statics
  static void trans(const Matrix &A, Matrix &At);
  static void mul(const Matrix &A, const Matrix &B, Matrix &C);
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

void Matrix::trans(const Matrix &A, Matrix &At) {
  assert(A.nrows == At.ncols);
  assert(A.ncols == At.nrows);

  for (int row=0; row<A.nrows; row++) {
    for (int col=0; col<A.ncols; col++) {
      At.m[col][row]=A.m[row][col];
    }
  }
}

void Matrix::mul(const Matrix &A, const Matrix &B, Matrix &C) {
  assert(A.ncols == B.nrows);
  assert(C.nrows == A.nrows);
  assert(C.ncols == B.ncols);
  // i=row, j=col
  for (int row=0; row<C.nrows; row++) {
    for (int col=0; col<C.ncols; col++) {
      float s = 0.0;
      for (int r=0; r<A.ncols ;r++) {
        s += A.m[row][r]*B.m[r][col];
      }
      C.m[row][col]=s;
    }
  }
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
  int m = 3, n = 2;
  int ni= m;

  Matrix A(n, ni);
  // a1
  A.set(0,0,1);
  A.set(1,0,1);
  // a2
  A.set(0,1,4);
  A.set(1,1,1);
  // a3
  A.set(0,2,1);
  A.set(1,2,4);

  cout<<"Test A:";
  A.print(cout);

  Matrix At(ni, n);

  Matrix::trans(A, At);
  cout<<"Test At:";
  At.print(cout);

  Matrix B(2,2); // 2 rows, 3 columns

  Matrix::mul(A, At, B);

  Vector C(2);
  C.set(0,1);
  C.set(1,2);

  cout << "Выходные данные:" << endl;
  B.print(cout);
  C.print(cout);

  return 0;
}
