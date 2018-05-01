#include "Matrix.h"

#pragma once
class MatricesOperations
{
private:
	//Matrix a;
	//Matrix vectorB;
	int iterations;
	double duration;

public:
	MatricesOperations();

	Matrix createBandMatrix(double a1, double a2, double a3, int n);
	Matrix createIdentityMatrix(int n);
	Matrix createSpecVectorB(int f, int n);

	//void loadMatrixA(Matrix a);
	//void loadVectorB(Matrix vectorB);

	Matrix solveJacobi(Matrix a, Matrix vectorB, double residuumNormLimit);
	Matrix solveGS(Matrix a, Matrix vectorB, double residuumNormLimit);
	Matrix solveLUfactorization(Matrix a, Matrix vectorB);

	double calculateVectorNorm(Matrix vector);

	double getDurationTime();
	int getIterations();

	~MatricesOperations();
};

