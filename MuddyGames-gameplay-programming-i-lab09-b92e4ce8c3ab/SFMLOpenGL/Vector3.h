
class Vector3
{
public:
	float m_x;
	float m_y;
	float m_z;
	Vector3() = default;
	Vector3(float x, float y, float z);


	float getX();
	void setX(float X);
	float getY();
	void setY(float X);
	float getZ();
	void setZ(float X);
	double length();
	double lengthSquared();
	void normalise();
	Vector3 add(Vector3 V1, Vector3 V2);
	Vector3 minus(Vector3 V1, Vector3 V2);
	Vector3 negate(Vector3 V);
	
	Vector3 scalarDouble(double k, Vector3 V1);
	Vector3 scalarFloat(float k, Vector3 V1);
	Vector3 scalar(int k, Vector3 V1);
	Vector3 vectorProduct(Vector3 V1, Vector3 V2);


};