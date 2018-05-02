#include <iostream>
#include <cstdio>
#include "Matrix.h"
#include "MatricesOperations.h"

using namespace std;

int main() {
	Matrix bandMatrix, vectorB, resultMatrix;
	MatricesOperations matOp;
	int n;
	double	residuumNormLimit;

	// Zadanie A
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n); 
		vectorB = matOp.createSpecVectorB(5, n);
		cout << "Macierz A: \n";
		bandMatrix.print(10, 10);
		cout << "Wektor b: \n";
		vectorB.print(10, 1);
	}

	// Zadanie B
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(5 + 3, -1, -1, n); 
		vectorB = matOp.createSpecVectorB(5, n); 
		matOp.solveJacobi(bandMatrix, vectorB, residuumNormLimit);
		cout << "Jacobi: Czas: " << matOp.getDurationTime() << "s   Iteracje: " << matOp.getIterations() << endl;
		matOp.solveGS(bandMatrix, vectorB, residuumNormLimit);
		cout << "Gauss-Seidel: Czas: " << matOp.getDurationTime() << "s   Iteracje: " << matOp.getIterations() << endl;
	}

	// Zadanie C
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(3, -1, -1, n);
		vectorB = matOp.createSpecVectorB(5, n);
		matOp.solveJacobi(bandMatrix, vectorB, residuumNormLimit);
		//matOp.solveGS(bandMatrix, vectorB, residuumNormLimit);
	}

	// Zadanie D	
	if (0) {
		n = 951;
		residuumNormLimit = 0.000000001; // 10^-9
		bandMatrix = matOp.createBandMatrix(3, -1, -1, n);
		vectorB = matOp.createSpecVectorB(5, n);
		resultMatrix = matOp.solveLUfactorization(bandMatrix, vectorB);
		cout << "Faktoryzacja LU: Czas: " << matOp.getDurationTime() <<
			"   Wartosc normy z residuum: " << matOp.calculateVectorNorm((bandMatrix * resultMatrix) - vectorB) << endl;
	}

	// Zadanie E
	if (0) {
		int n[9] = { 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000 };
		double times[3];
		char textFormat[] = "|%10.10s|%15s|%15s|%15s|\n";
		char valuesFormat[] = "|%-10d|%14fs|%14fs|%14fs|\n";
		char sep[15] = "--------------";
		residuumNormLimit = 0.000000001; // 10^-9

		printf("Czas trwania poszczegolnych algorytmow dla poszczegolnych wartosci n: \n\n");
		printf(textFormat, "Wartosc n", "Jacobi", "Gauss-Seidel", "Faktoryzcja LU");
		printf(textFormat, sep, sep, sep, sep);

		for (int i = 0; i < 9; ++i) {
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