#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int ROW = 100;
const int COL = 100;

//bool isLoadFile(TypeFile &file) {
//  if(file.fail() || file.is_open()) {
//    cout << "/n Can't open file";
//    return false;
//  }
//  return true;
//}

void cOutDataFileToScreen(ifstream &file) {
  string text;
  while ( getline(file, text) ) {
    cout << text + "\n";
  }
  cout << "------------------------------- \n";
}

// BT1
int writeNumberToFile(char filename[20]){
  ofstream myFile(filename);

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

void exportMatrixToScreen(int mt[ROW][COL], int m, int n){
  string matrixText = "";
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      matrixText += to_string(mt[i][j]) + " ";
    }
    matrixText += "\n";
  }
  cout << matrixText;
  cout << "------------------------------- \n";
}

void writeMatrixToFile(ofstream &file, int mt[ROW][COL], int row, int col) {
  string matrixText = "";
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      matrixText += to_string(mt[i][j]) + " ";
    }
    matrixText += "\n";
  }
  file << matrixText;
}

int multiplyTwoMatricesFromFile(char fileNameA[20], char fileNameB[20], char fileNameC[20]) {
  ifstream fileMatrixAIn(fileNameA);
  ifstream fileMatrixBIn(fileNameB);
  ofstream fileMatrixC(fileNameC);

  int rowA, colA, rowB, colB;
  fileMatrixAIn >> rowA >> colA;
  fileMatrixBIn >> rowB >> colB;

  int mtA[ROW][COL];
  int mtB[ROW][COL];
  int mtC[ROW][COL];

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colA; j++) {
      fileMatrixAIn >> mtA[i][j];
    }
  }

  for (int i = 0; i < rowB; i++) {
    for (int j = 0; j < colB; j++) {
      fileMatrixBIn >> mtB[i][j];
    }
  }

  for (int i = 0; i < rowA; i++) {
    for (int j = 0; j < colB; j++) {
      mtC[i][j] = 0;
      for (int k = 0; k < colA; k++) {
        mtC[i][j] += mtA[i][k] * mtB[k][j];
      }
    }
  }

  //exportMatrixToScreen(mtC, rowA, colB);
  writeMatrixToFile(fileMatrixC, mtC, rowA, colB);
  fileMatrixC.close();
  ifstream fileMatrixCIn(fileNameC);

  exportMatrixToScreen(mtA, rowA, colA);
  exportMatrixToScreen(mtB, rowB, colB);
  cOutDataFileToScreen(fileMatrixCIn);

  fileMatrixAIn.close();
  fileMatrixBIn.close();
  fileMatrixCIn.close();
  return 0;
}

// BT3
struct student {
  string codeStudent;
  string fullName;
  string className;
  string birthday;
  int age;
};
typedef struct student Student;

void writeInfoStudent(ifstream &fileStudents, Student &st) {
  getline(fileStudents, st.codeStudent, '|');
  getline(fileStudents, st.fullName, '|');
  getline(fileStudents, st.className, '|');
  getline(fileStudents, st.birthday, '|');
  string age;
  getline(fileStudents, age);
  stringstream geek(age);
  geek >> st.age;
}

void readFileStudents(char filename[50]) {
  Student students[1000];
  ifstream fileStudents(filename);
  string firstLine;
  getline(fileStudents, firstLine);
  int i = 0;
  while (fileStudents.eof() == false) {
    writeInfoStudent(fileStudents, students[i++]);
  }

  for (int j = 0; j < i - 1; j++) {
    cout << students[j].codeStudent << students[j].fullName << students[j].className << students[j].birthday << students[j].age << "\n";
    cout << "-----------------\n";
  }

  fileStudents.close();
}

int main () {
  // BT1:
  char fileNameBT1[20] = "bt1.txt";
  writeNumberToFile(fileNameBT1);

  // BT2
  char matrixA[20] = "mtA.txt";
  char matrixB[20] = "mtB.txt";
  char matrixC[20] = "mtC.txt";
  multiplyTwoMatricesFromFile(matrixA, matrixB, matrixC);

  // BT3
  char filenameStudent[50] = "bt3.txt";
  readFileStudents(filenameStudent);
  
  return 0;
}
