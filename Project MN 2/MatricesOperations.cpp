#include "MatricesOperations.h"

#include <cmath>
#include "Matrix.h"

#define RES_NORM_LIMIT 0.000000001


MatricesOperations::MatricesOperations()
{
}

Matrix MatricesOperations::createBandMatrix(double a1, double a2, double a3, int n)
{
	Matrix mat(n, n, 0);
	mat(0, 0) = a1;
	mat(1, 1) = a1;
	mat(0, 1) = a2;
	mat(1, 0) = a2;

	for (int i = 2; i < n; ++i) {
		mat(i, i) = a1;
		mat(i - 1, i) = a2;
		mat(i, i - 1) = a2;
		mat(i - 2, i) = a3;
		mat(i, i - 2) = a3;
	}
	return mat;
}

Matrix MatricesOperations::createSpecVectorB(double f, int n)
{
	Matrix vect(n, 1);
	for (int i = 0; i < n; ++i)
		vect(i) = sin((i + 1)*(f + 1));

	return vect;
}

void MatricesOperations::loadMatrixA(Matrix a)
{
	this->a = a;
}

void MatricesOperations::loadVectorB(Matrix vectorB)
{
	this->vectorB = vectorB;
}

Matrix MatricesOperations::solveJacobi()
{
	return Matrix();
}

Matrix MatricesOperations::solveGS()
{
	return Matrix();
}

MatricesOperations::~MatricesOperations()
{
}
