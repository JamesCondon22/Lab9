# include <iostream>

#include "Matrix3.h"
#include "Vector3.h"
#include <stdio.h> 
#include <math.h>  


Matrix3::Matrix3()
{
	A11 = 0.0;
	A12 = 0.0;
	A13 = 0.0;
	A21 = 0.0;
	A22 = 0.0;
	A23 = 0.0;
	A31 = 0.0;
	A32 = 0.0;
	A33 = 0.0;
}

// Constructor 2
Matrix3::Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3)
{  // To allow 3 rows of vectors to be declared as a matrix
	A11 = Row1.getX();
	A12 = Row1.getY();
	A13 = Row1.getZ();
	A21 = Row2.getX();
	A22 = Row2.getY();
	A23 = Row2.getZ();
	A31 = Row3.getX();
	A32 = Row3.getY();
	A33 = Row3.getZ();
}
// Constructor 3
Matrix3::Matrix3(float _A11, float _A12, float _A13,
	float _A21, float _A22, float _A23,
	float _A31, float _A32, float _A33)
{// to allow nine double values
	A11 = _A11;
	A12 = _A12;
	A13 = _A13;
	A21 = _A21;
	A22 = _A22;
	A23 = _A23;
	A31 = _A31;
	A32 = _A32;
	A33 = _A33;
}

Vector3 Matrix3::matByVec(Matrix3 M1, Vector3 V1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return  Vector3(M1.A11 * V1.m_x + M1.A12 * V1.m_y + M1.A13 * V1.m_z,
		M1.A21 * V1.m_x + M1.A22 * V1.m_y + M1.A23 * V1.m_z,
		M1.A31 * V1.m_x + M1.A32 * V1.m_y + M1.A33 * V1.m_z);
}

Vector3 Matrix3::vecByMat(Vector3 V1, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a vector
	return  Vector3(M1.A11 * V1.m_x + M1.A21 * V1.m_y + M1.A31 * V1.m_z,
		M1.A12 * V1.m_x + M1.A22 * V1.m_y + M1.A32 * V1.m_z,
		M1.A13 * V1.m_x + M1.A23 * V1.m_y + M1.A33 * V1.m_z);
}

Matrix3 Matrix3::Transpose(Matrix3 M1)
{// a method to transpose a given matrix
	return  Matrix3(M1.A11, M1.A21, M1.A31,
		M1.A12, M1.A22, M1.A32,
		M1.A13, M1.A23, M1.A33);
}
Matrix3 Matrix3::add(Matrix3 M1, Matrix3 M2)
{// An overloaded operator + to return the  sum of two matrix 
	return  Matrix3(M1.A11 + M2.A11, M1.A12 + M2.A12, M1.A13 + M2.A13,
		M1.A21 + M2.A21, M1.A22 + M2.A22, M1.A23 + M2.A23,
		M1.A31 + M2.A31, M1.A32 + M2.A32, M1.A33 + M2.A33);
}
Matrix3 Matrix3::minus(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  difference of two matrix
	return  Matrix3(M1.A11 - M2.A11, M1.A12 - M2.A12, M1.A13 - M2.A13,
		M1.A21 - M2.A21, M1.A22 - M2.A22, M1.A23 - M2.A23,
		M1.A31 - M2.A31, M1.A32 - M2.A32, M1.A33 - M2.A33);
}

Matrix3 Matrix3::scalar(double x, Matrix3 M1)
{// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3 answer = Matrix3();
	answer.A11 = M1.A11 * x;
	answer.A12 = M1.A12 * x;
	answer.A13 = M1.A13 * x;

	answer.A21 = M1.A21 * x;
	answer.A22 = M1.A22 * x;
	answer.A23 = M1.A23 * x;

	answer.A31 = M1.A31 * x;
	answer.A32 = M1.A32 * x;
	answer.A33 = M1.A33 * x; ;

	return answer;
}

Matrix3 Matrix3::multiply(Matrix3 M1, Matrix3 M2)
{// An overloaded operator * to return the  product of two matrix
	return Matrix3(M1.A11 * M2.A11 + M1.A12 * M2.A21 + M1.A13 * M2.A31, M1.A11 * M2.A12 + M1.A12 * M2.A22 + M1.A13 * M2.A32, M1.A11 * M2.A13 + M1.A12 * M2.A23 + M1.A13 * M2.A33,
		M1.A21 * M2.A11 + M1.A22 * M2.A21 + M1.A23 * M2.A31, M1.A21 * M2.A12 + M1.A22 * M2.A22 + M1.A23 * M2.A32, M1.A21 * M2.A13 + M1.A22 * M2.A23 + M1.A23 * M2.A33,
		M1.A31 * M2.A11 + M1.A32 * M2.A21 + M1.A33 * M2.A31, M1.A31 * M2.A12 + M1.A32 * M2.A22 + M1.A33 * M2.A32, M1.A31 * M2.A13 + M1.A32 * M2.A23 + M1.A33 * M2.A33);
}


double Matrix3::determinant(Matrix3 M1)
{// method to return the determinant of a 3x3 matrix
 //                     aei      -     ahf                  + dhc                     - gec                      +    gbh                    -     dbi   
	return M1.A11 * M1.A22 * M1.A33 - M1.A11 * M1.A32 * M1.A23 + M1.A21 * M1.A32 * M1.A13 - M1.A31 * M1.A22 * M1.A13 + M1.A31 * M1.A12 * M1.A23 - M1.A21 * M1.A12 * M1.A33;
}

Matrix3 Matrix3::inverse(Matrix3 M1)
{
	// method to return the inverse of a matrix if exists else zero vector
	double det = determinant(M1);
	if (det == 0)
		return Matrix3();
	else
	{
		double scale = 1 / det;
		Matrix3 answer;
		answer.A11 = scale * (M1.A22 * M1.A33 - M1.A23 * M1.A32); // ei-fh
		answer.A12 = scale * (M1.A13 * M1.A32 - M1.A12 * M1.A33); // ch-bi
		answer.A13 = scale * (M1.A12 * M1.A23 - M1.A13 * M1.A22); // ch-bi

		answer.A21 = scale * (M1.A23 * M1.A31 - M1.A21 * M1.A33); // fg-di
		answer.A22 = scale * (M1.A11 * M1.A33 - M1.A13 * M1.A31); // ai-cg
		answer.A23 = scale * (M1.A13 * M1.A21 - M1.A11 * M1.A23); // cd-af


		answer.A31 = scale * (M1.A21 * M1.A32 - M1.A22 * M1.A31); // dh-eg
		answer.A32 = scale * (M1.A12 * M1.A31 - M1.A11 * M1.A32); // bg-ah
		answer.A33 = scale * (M1.A11 * M1.A22 - M1.A12 * M1.A21); // ae-bd

		return answer;
	}

}



Matrix3 Matrix3::translate(int dx, int dy)
{
	Matrix3 answer;
	answer.A11 = 1;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = 1;
	answer.A23 = 0;
	answer.A31 = dx;
	answer.A32 = dy;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::scale(int dx, int dy)
{
	Matrix3 answer;
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dy / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}

Matrix3 Matrix3::negate(Matrix3 M1)
{
	return Matrix3(-1 * M1.A11, -1 * M1.A12, -1 * M1.A13, -1 * M1.A21, -1 * M1.A22, -1 * M1.A23, -1 * M1.A31, -1 * M1.A32, -1 * M1.A33);
}

Vector3 Matrix3::rotationX(Vector3 V, float _angle)
{
	float radians = 3.14 / 180.0 * _angle;
	Vector3 answer = V;
	Matrix3 mat;
	mat.A11 = 1.0f;
	mat.A12 = 0;
	mat.A13 = 0;
	mat.A21 = 0;
	mat.A22 = cos(radians);
	mat.A23 = -sin(radians);
	mat.A31 = 0;
	mat.A32 = sin(radians);
	mat.A33 = cos(radians);

	answer = mat.matByVec(mat, answer);
	return answer;
}
Vector3 Matrix3::rotationY(Vector3 V, float _angle)
{
	float radians = 3.14 / 180.0 * _angle;
	Vector3 answer = V;
	Matrix3 mat;
	mat.A11 = cos(radians);
	mat.A12 = 0;
	mat.A13 = sin(radians);
	mat.A21 = 0;
	mat.A22 = 1.0f;
	mat.A23 = 0;
	mat.A31 = -sin(radians);
	mat.A32 = 0;
	mat.A33 = cos(radians);

	answer = mat.matByVec(mat, answer);
	return answer;
}
Matrix3 Matrix3::rotationZ(int _angle)
{
	double radians = 3.14 / 180 * _angle;
	Matrix3 answer;
	answer.A11 = cos(radians);
	answer.A12 = sin(radians);
	answer.A13 = 0;
	answer.A21 = sin(radians);
	answer.A22 = cos(radians);
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = 1;

	return answer;
}
Matrix3 Matrix3::scale3D(int dx)
{
	Matrix3 answer;
	answer.A11 = (double)dx / 100;
	answer.A12 = 0;
	answer.A13 = 0;
	answer.A21 = 0;
	answer.A22 = (double)dx / 100;
	answer.A23 = 0;
	answer.A31 = 0;
	answer.A32 = 0;
	answer.A33 = (double)dx / 100;

	return answer;
}
