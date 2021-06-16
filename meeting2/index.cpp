#include <iostream>
#include <fstream>
using namespace std;

//enum class TypeFile {ofstream, ifstream};
//bool isLoadFile(TypeFile &file) {
//  if(file.fail() || file.is_open()) {
//    cout << "/n Can't open file";
//    return false;
//  } 
//  return true;
//}

void cOutDataFileToScreen(ifstream &file) {
  string text;
  while (getline (file, text)) {
    cout << text + "\n";
  }
  cout << "------------------------------- \n";
}

// BT1
int writeNumberToFile(char filename[20]){
  ofstream myFile(filename);
  //if(!isloadfile(myfile)) return 0;

  int numbers = 100, i = 1;
  string content = "";

  for (; i <= numbers; i++) {
    content += " " + to_string(i);
    if(i % 10 == 0 ) content += "\n";
  }

  myFile << content;
  myFile.close();

  ifstream file(filename);
  cOutDataFileToScreen(file);
  file.close();
  return 0;
}
// BT2
//template <int rows, int rows>
//class Matrix {
//  int mt;
//  Matrix(int rows, int cols) {
//    this.mt = this.mt[rows][cols];
//  }
//};
//struct matrix {
//  int col, row;
//  double data[1];
//};
//typedef matrix Matrix;

//Matrix createMatrixFromFile(ifstream *matrix) {
 
//};

int writeMarixsFromFile(char fileNameA[20], char fileNameB[20], char fileNameC[20]) {
  ifstream fileMatrixA(fileNameA);
  ifstream fileMatrixB(fileNameB);
  ofstream fileMatrixC(fileNameC);

  int rowsA, colsA, rowsB, colsB;
  fileMatrixA >> rowsA >> colsA; 
  fileMatrixB >> rowsB >> colsB; 

  int mtA[rowsA][colsB], mtB[rowsB][colsB], mtC[rowsA][colsB];

  for (int i = 0; i < colsA; i++) {
    for (int j = 0; j < rowsA; j++) {
      fileMatrixA >> mtA[i][j];
    }
  }

  for (int i = 0; i < colsB; i++) {
    for (int j = 0; j < rowsB; j++) {
      fileMatrixB >> mtB[i][j];
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
       mtC[i][j] = 0;
       for (int k = 0; k < colsA; k++) {
         mtC[i][j] += mtA[i][k]*mtB[k][j];
       }
    }
  }

  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsB; j++) {
      //fileMatrixB >> mtB[i][j];
      cout << mtC[i][j];
    }
  }

  fileMatrixC.close();
  ifstream fileMatrixCIn(fileNameC);
  cOutDataFileToScreen(fileMatrixA);
  cOutDataFileToScreen(fileMatrixB);
  cOutDataFileToScreen(fileMatrixCIn);
  fileMatrixA.close();
  fileMatrixB.close();
  fileMatrixC.close();
  return 0; 
}

int main () {
  // BT1:
  char fileNameBT1[20] = "bt1.txt";
  writeNumberToFile(fileNameBT1);

  // bT2 
  char maTrixA[20] = "mtA.txt";
  char maTrixB[20] = "mtB.txt";
  char maTrixC[20] = "mtC.txt";
  writeMarixsFromFile(maTrixA, maTrixB, maTrixC);
  return 0;
}
