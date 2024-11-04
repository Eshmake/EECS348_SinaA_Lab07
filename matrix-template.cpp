
#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin();

  // 2. Display a matrix
  void display() const;

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const;

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const;

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const;

  // 6. Swap matrix rows
  void swapRows(int row1, int row2);
  
};

//Matrix method definition

void Matrix::readFromStdin(){
  string filename;
  string line;

  cout << "Enter file name: " << endl;
  cin >> filename;

  static ifstream file(filename);

  if(!file.is_open()){
    cerr << "File can not be opened" << endl;
  }
  else{
    for(int i = 0; i < SIZE; i++){
      for(int j = 0; j < SIZE; j++){
        file >> data[i][j]; 
      }
    }
  }
}


void Matrix::display() const{
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}


Matrix Matrix::operator+(const Matrix& other) const {
  Matrix sumMat;

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
     sumMat.data[i][j] = data[i][j] + other.data[i][j];
    }
  }

  return sumMat;
}


Matrix Matrix::operator*(const Matrix& other) const {
  Matrix prodMat;
    
  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      prodMat.data[i][j] = 0;
      for(int c = 0; c < SIZE; c++){
        prodMat.data[i][j] += data[i][c] * other.data[c][j];
      }
    }
  }

  return prodMat;
}


int Matrix::sumOfDiagonals() const{
  int* mainDiag = new int;
  int* secDiag = new int;


  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      if(i == j){
        *mainDiag += data[i][j];}

      if(j == (SIZE-1)-i){
        *secDiag += data[i][j];}

    }
  }

  int sum = *mainDiag + *secDiag;

  delete mainDiag;
  delete secDiag;

  return sum;
}


void Matrix::swapRows(int row1, int row2){
  if((row1 >= 0 && row1 < SIZE) && (row2 >= 0 && row2 < SIZE)){
    int temp;

    for(int i = 0; i < SIZE; i++){
      temp = data[row1][i];
      data[row1][i] = data[row2][i];
      data[row2][i] = temp;
    }

  }
  else{
    cerr << "Invalid row and column values" << endl;
  }
}


int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  cout << "\n";

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  cout << "\n";

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  cout << "\n";

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "\n";

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  cout << "\n";

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  cout << "\n";

  return 0;
}
