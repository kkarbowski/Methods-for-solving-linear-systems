#include <iostream>
#include "Matrix.h"
#include "MatricesOperations.h"

using namespace std;
//165351
int main() {
	Matrix bandMatrix, vectorB, resultMatrix;
	MatricesOperations matOp;
	int n = 951;

	bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n);
	vectorB = matOp.createSpecVectorB(5, n);

	matOp.loadMatrixA(bandMatrix);
	matOp.loadVectorB(vectorB);
	matOp.solveJacobi();
	cout << "Czas: " << matOp.getDurationTime() << "   Iteracje: " << matOp.getIterations() << endl;
	getchar();
	return 0;
}


/*Matrix testVect = matOp.createSpecVectorB(5, 5);
Matrix testMat = matOp.createBandMatrix(5 + 3, -1, -1, 5);

for (int i = 0; i < 5; ++i) {
for (int j = 0; j < 5; ++j) {
cout << testMat(i, j) << "\t";
}
cout << endl;
}
cout << endl;
testVect = testMat * testVect;
for (int i = 0; i < 5; ++i) {
cout << testVect(i) << endl;
}
cout << endl;
getchar();*/



//
//Matrix test(3, 3);
//test(0) = 1;
//test(1) = 2;
//test(2) = 3;
//test(3) = 4;
//test(4) = 5;
//test(5) = 6;
//test(6) = 7;
//test(7) = 8;
//test(8) = 9;
//cout << test(2, 0);
//getchar();




//