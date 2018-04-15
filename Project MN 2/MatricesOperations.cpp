#include "MatricesOperations.h"

#include <cmath>
#include <ctime>
#include <iostream>
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

Matrix MatricesOperations::createSpecVectorB(int f, int n)
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
	int height = vectorB.getHeight();
	Matrix resultVect(height, 1);
	Matrix copyResultVect(height, 1, 1);
	Matrix residuum(height, 1);
	//Matrix tmpVect1(vectorB.getHeight(), 1, 0);
	//Matrix tmpVect2(vectorB.getHeight(), 1, 0);
	double tmp = 0;
	clock_t start, end;
	iterations = 0;
	start = clock();
	while (true) {
		++iterations;
		for (int i = 0; i < height; ++i) {
			//for (int j = 0; j < i; ++j)
			//	tmp += (a(i, j)*copyResultVect(j));
			//for (int j = i + 1; j < height; ++j)
			//	tmp += (a(i, j)*copyResultVect(j));
			for (int j = 0; j < height; ++j)
				tmp += a(i, j)*copyResultVect(j);
			tmp -= a(i, i)*copyResultVect(i);
			resultVect(i) = (vectorB(i) - tmp) / a(i, i);
			tmp = 0;
		}
		residuum = (a * resultVect) - vectorB;
		std::cout << calculateVectorNorm(residuum) << "   ";
		if (calculateVectorNorm(residuum) < RES_NORM_LIMIT)
			break;
		copyResultVect = resultVect;
	}
	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
	return resultVect;
}

Matrix MatricesOperations::solveGS()
{
	return Matrix();
}

double MatricesOperations::calculateVectorNorm(Matrix vector)
{
	double tmp = 0;
	for (int i = 0; i < vector.getHeight(); ++i)
		tmp += vector(i) * vector(i);
	return sqrt(tmp);
}

double MatricesOperations::getDurationTime()
{
	return duration;
}

int MatricesOperations::getIterations()
{
	return iterations;
}

MatricesOperations::~MatricesOperations()
{
}
