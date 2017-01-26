class Vector3;


class Matrix3
{
private:
	double A11;
	double A12;
	double A13;
	double A21;
	double A22;
	double A23;
	double A31;
	double A32;
	double A33;

public:
	double m_x = 0;
	double m_y = 0;
	double m_z = 0;

	Matrix3();
	Matrix3(Vector3 Row1, Vector3 Row2, Vector3 Row3);
	Matrix3(float _A11, float _A12, float _A13,
		float _A21, float _A22, float _A23,
		float _A31, float _A32, float _A33);
	Vector3 matByVec(Matrix3 M1, Vector3 V1);
	Vector3 vecByMat(Vector3 V1, Matrix3 M1);
	Matrix3 Transpose(Matrix3 M1);
	Matrix3 add(Matrix3 M1, Matrix3 M2);
	Matrix3 minus(Matrix3 M1, Matrix3 M2);
	Matrix3 scalar(double x, Matrix3 M1);
	Matrix3 multiply(Matrix3 M1, Matrix3 M2);
	double determinant(Matrix3 M1);
	Matrix3 inverse(Matrix3 M1);

	Matrix3 translate(int dx, int dy);
	Matrix3 scale(int dx, int dy);
	Matrix3 negate(Matrix3 M1);
	Vector3 rotationX(Vector3 V,float _angle);
	Vector3 rotationY(Vector3 V, float _angle);
	Matrix3 rotationZ(int _angle);
	Matrix3 scale3D(int dx);
};
