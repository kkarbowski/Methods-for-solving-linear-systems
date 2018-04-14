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

	getchar();
	return 0;
}