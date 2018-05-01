#include <iostream>
#include <cstdio>
#include "Matrix.h"
#include "MatricesOperations.h"

using namespace std;
//165351
int main() {
	Matrix bandMatrix, vectorB, resultMatrix;
	MatricesOperations matOp;
	int n;
	double	residuumNormLimit, // 10^-9
		residuumNorm; 

	// Zadanie A
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n); 
		vectorB = matOp.createSpecVectorB(5, n);
		bandMatrix.print(10, 10);
		vectorB.print(10, 1);
	}

	// Zadanie B
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n); 
		vectorB = matOp.createSpecVectorB(5, n); 
		matOp.solveJacobi(bandMatrix, vectorB, residuumNormLimit);
		cout << "Jacobi: Czas: " << matOp.getDurationTime() << "   Iteracje: " << matOp.getIterations() << endl;
		matOp.solveGS(bandMatrix, vectorB, residuumNormLimit);
		cout << "Gauss-Seidel: Czas: " << matOp.getDurationTime() << "   Iteracje: " << matOp.getIterations() << endl;
	}

	// Zadanie C
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(3, -1, -1, n);
		vectorB = matOp.createSpecVectorB(5, n);
		//matOp.solveJacobi(bandMatrix, vectorB, residuumNormLimit);
		matOp.solveGS(bandMatrix, vectorB, residuumNormLimit);
	}

	// Zadanie D	
	if (0) {
		n = 1951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(3, -1, -1, n);
		vectorB = matOp.createSpecVectorB(5, n);
		resultMatrix = matOp.solveLUfactorization(bandMatrix, vectorB);
		cout << "Faktoryzacja LU: Czas: " << matOp.getDurationTime() <<
			"   Wartosc normy z residuum: " << matOp.calculateVectorNorm((bandMatrix * resultMatrix) - vectorB) << endl;
	}

	// Zadanie E
	if (1) {
		int n[9] = { 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000 };
		double times[3];
		char textFormat[] = "|%10.10s|%15s|%15s|%15s|\n";
		char valuesFormat[] = "|%-10d|%14fs|%14fs|%14fs|\n";
		char sep[15] = "--------------";
		residuumNormLimit = 0.000000001; // 10^-9

		printf("Czas trwania poszczegolnych algorytmow dla poszczegolnych wartosci n: \n\n");
		printf(textFormat, "Wartosc n", "Jacobi", "Gauss-Seidel", "Faktoryzcja LU");
		printf(textFormat, sep, sep, sep, sep);

		for (int i = 0; i < 3; ++i) {
			bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n[i]);
			vectorB = matOp.createSpecVectorB(5, n[i]);

			matOp.solveJacobi(bandMatrix, vectorB, residuumNormLimit);
			times[0] = matOp.getDurationTime();
			matOp.solveGS(bandMatrix, vectorB, residuumNormLimit);
			times[1] = matOp.getDurationTime();
			matOp.solveLUfactorization(bandMatrix, vectorB);
			times[2] = matOp.getDurationTime();
			printf(valuesFormat, n[i], times[0], times[1], times[2]);
		}
	}
	getchar();
	return 0;
}

//printf("|%5s|%5s|%5s|%5s|", arg0, arg1, arg2, arg3);



////test
//Matrix A(4, 4);
//vectorB = matOp.createSpecVectorB(5, 4); // Wszystkie Zadania
//A(0) = 2, A(1) = 1, A(2) = 1, A(3) = 0;
//A(4) = 4, A(5) = 3, A(6) = 3, A(7) = 1;
//A(8) = 8, A(9) = 7, A(10) = 9, A(11) = 5;
//A(12) = 6, A(13) = 7, A(14) = 9, A(15) = 8;
//
//resultMatrix = matOp.solveLUfactorization(A, vectorB);



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