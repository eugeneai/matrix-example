#include <vector>
#include <iostream>
#include <string>

using namespace std;

typedef vector<vector<float>> matrix_t;

class Matrix {

private:
  Matrix() = delete;

public:
  matrix_t m;

  Matrix(int nrows, int ncols);
  void set(int row, int col, float value);
  void print(ostream &s);
};

class Vector {

public:
  Vector(int size);
  void set(int index, float value);
  void print(ostream &s);
};


// ------------ Implementations ----------------------


Matrix::Matrix(int nrows, int ncols) {

}
void Matrix::set(int row, int col, float value) {

}

void Matrix::print(ostream &s){
  s << "Выводим Матрицу" << endl;
}





Vector::Vector(int size) {

}
void Vector::set(int index, float value) {

}
void Vector::print(ostream &s) {
  s << "Выводим Вектор"  << endl;
}



// ------------ End of Implementations --------------




int main (int __argc, char **__argv) {
  std::vector<std::string> args(__argv, __argv+__argc);

  Matrix B(2,2);
  B.set(0,0,1);
  B.set(1,1,2);
  Vector C(2);
  C.set(0,1);
  C.set(1,2);

  cout << "Выходные данные:" << endl;
  B.print(cout);
  C.print(cout);

  return 0;
}
