#include "Vector3.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
#include <vector>

// Constructor 2
Vector3::Vector3(float x1, float y1, float z1) :
	// To allow other values for X, Y and Z to be declared
	m_x(x1),
	m_y(y1),
	m_z(z1)
{
}

double Vector3::length()
{  // A method to return the length of the vector
	return (double)sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Vector3::lengthSquared()
{  // A method to return the length squared of the vector
	return (m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vector3::normalise()
{  // A method to reduce the length of the vector to 1.0 
   // keeping the direction the same
	if (length() > 0.0)
	{  // Check for divide by zero
		double magnit = length();
		m_x /= magnit;
		m_y /= magnit;
		m_z /= magnit;
	}
}




Vector3 Vector3::add(Vector3 V1, Vector3 V2)
{  // An overloaded operator + to return the sum of 2 vectors
	return Vector3(V1.m_x + V2.m_x, V1.m_y + V2.m_y, V1.m_z + V2.m_z);

}

Vector3 Vector3::minus(Vector3 V1, Vector3 V2)
{ // An overloaded operator - to return the difference of 2 vectors
	return Vector3(V1.m_x - V2.m_x, V1.m_y - V2.m_y, V1.m_z - V2.m_z);
}

Vector3 Vector3::negate(Vector3 V)
{// An overloaded operator - to return the negation of a single vector
	Vector3 V1 = Vector3();
	V1.m_x = -V.m_x;
	V1.m_y = -V.m_y;
	V1.m_z = -V.m_z;
	return V1;
}



Vector3 Vector3::scalarDouble(double k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.m_x * (float)k, V1.m_y * (float)k, V1.m_z * (float)k);
}

Vector3 Vector3::scalarFloat(float k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.m_x * k, V1.m_y * k, V1.m_z * k);
}

Vector3 Vector3::scalar(int k, Vector3 V1)
{// An overloaded operator * to return the product of a scalar by a vector
	return Vector3(V1.m_x * k, V1.m_y * k, V1.m_z * k);
}

Vector3 Vector3::vectorProduct(Vector3 V1, Vector3 V2)
{// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3(V1.m_y * V2.m_z - V1.m_z * V2.m_y, V1.m_z * V2.m_x - V1.m_x * V2.m_z, V1.m_x * V2.m_y - V1.m_y * V2.m_x);
}
void Vector3::setX(float X)
{
	m_x = X;
}
float Vector3::getX()
{
	return m_x;
}
void Vector3::setY(float Y)
{
	m_y = Y;
}
float Vector3::getY()
{
	return m_y;
}
void Vector3::setZ(float Z)
{
	m_z = Z;
}
float Vector3::getZ()
{
	return m_z;
}

