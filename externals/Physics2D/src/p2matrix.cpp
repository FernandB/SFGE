/*
MIT License

Copyright (c) 2017 SAE Institute Switzerland AG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <p2matrix.h>
#include <array>
p2Mat22::p2Mat22()
{
}

p2Mat22::p2Mat22(p2Vec2 r1, p2Vec2 r2)
{
	rows[0] = r1;
	rows[1] = r2;
}

p2Mat22 p2Mat22::operator+(p2Mat22 m1)
{
	p2Mat22 finaleMatrix;
	finaleMatrix.rows[0] = rows[0] + m1.rows[0];
	finaleMatrix.rows[1] = rows[1] + m1.rows[1];

	return finaleMatrix;
}

p2Mat22 p2Mat22::operator-(p2Mat22 m1)
{
	p2Mat22 finaleMatrix;
	finaleMatrix.rows[0] = rows[0] - m1.rows[0];
	finaleMatrix.rows[1] = rows[1] - m1.rows[1];

	return finaleMatrix;
}

p2Mat22 p2Mat22::operator*(p2Mat22 m1)
{
	return p2Mat22();
}

p2Mat22 p2Mat22::operator*(p2Vec2 v)
{
	return p2Mat22(p2Vec2(rows[0].x*v.x, rows[0].y*v.y),p2Vec2(rows[1].x*v.x, rows[1].y*v.y));
}

p2Mat22 p2Mat22::operator*(float f)
{
	return p2Mat22();
}

p2Mat22 p2Mat22::operator/(float f)
{
	return p2Mat22();
}

p2Mat22 p2Mat22::Invert()
{

	if ((rows[0].x * rows[1].y)-(rows[0].y*rows[1].x) != 0)
	{
		float multiplicator = 1 / (rows[0].x * rows[1].y) - (rows[0].y*rows[1].x);
	return	p2Mat22(p2Vec2(rows[0].x*multiplicator, rows[0].y*multiplicator), p2Vec2(rows[1].x*multiplicator, rows[1].y*multiplicator));
	}

	return p2Mat22();

}

 p2Mat22 p2Mat22::RotationMatrix(float angle)
{
	 p2Mat22 R = p2Mat22(p2Vec2(cosf(angle),sinf(angle)),p2Vec2(-1*sinf(angle),cosf(angle)));
	 return R * p2Mat22(rows[0],rows[1]);

}
float p2Mat22::GetDeterminant()
{
	return (rows[0].x * rows[1].y) - (rows[0].y*rows[1].x);
}

p2Mat33::p2Mat33()
{
}

p2Mat33::p2Mat33(p2Vec3 r1, p2Vec3 r2, p2Vec3 r3)
{
	rows[0] = r1;
	rows[1] = r2;
	rows[2] = r3;
}

p2Mat33 p2Mat33::operator+(p2Mat33 m1)
{
	p2Mat33 finaleMatrix;
	finaleMatrix.rows[0] = p2Vec3().plus(rows[0],m1.rows[0]);
	finaleMatrix.rows[1] = p2Vec3().plus(rows[1],m1.rows[1]);

	return finaleMatrix;
}

p2Mat33 p2Mat33::operator-(p2Mat33 m1)
{
	p2Mat33 finaleMatrix;
	finaleMatrix.rows[0] = p2Vec3().minus(rows[0], m1.rows[0]);
	finaleMatrix.rows[1] = p2Vec3().minus(rows[1], m1.rows[1]);

	return finaleMatrix;
}

p2Mat33 p2Mat33::operator*(p2Mat33 m1)
{
	p2Vec3 col1=p2Vec3(rows[0].x*m1.rows[0].x, rows[1].x*m1.rows[0].y, rows[2].x*m1.rows[0].z);
	p2Vec3 col2 = p2Vec3(rows[0].y*m1.rows[1].x, rows[1].y*m1.rows[1].y, rows[2].y*m1.rows[1].z);
	p2Vec3 col3 = p2Vec3(rows[0].z*m1.rows[2].x, rows[1].z*m1.rows[2].y, rows[2].z*m1.rows[2].z);

	return p2Mat33(col1,col2,col3);
}

p2Mat33 p2Mat33::operator*(p2Vec3 v)
{
	p2Vec3 col1 = p2Vec3(rows[0].x*v.x, rows[1].x*v.y, rows[2].x*v.z);
	p2Vec3 col2 = p2Vec3(rows[0].y*v.x, rows[1].y*v.y, rows[2].y*v.z);
	p2Vec3 col3 = p2Vec3(rows[0].z*v.x, rows[1].z*v.y, rows[2].z*v.z);

	return p2Mat33(col1, col2, col3);
}

p2Mat33 p2Mat33::operator*(float f)
{
	p2Vec3 col1 = p2Vec3(rows[0].x*f, rows[1].x*f, rows[2].x*f);
	p2Vec3 col2 = p2Vec3(rows[0].y*f, rows[1].y*f, rows[2].y*f);
	p2Vec3 col3 = p2Vec3(rows[0].z*f, rows[1].z*f, rows[2].z*f);

	return p2Mat33(col1, col2, col3);
}

p2Mat33 p2Mat33::operator/(float f)
{
	p2Vec3 col1 = p2Vec3(rows[0].x/f, rows[1].x/f, rows[2].x/f);
	p2Vec3 col2 = p2Vec3(rows[0].y/f, rows[1].y/f, rows[2].y/f);
	p2Vec3 col3 = p2Vec3(rows[0].z/f, rows[1].z/f, rows[2].z/f);

	return p2Mat33(col1, col2, col3);
}

p2Mat33 p2Mat33::Invert()
{
	float multiplicator = 1 / GetDeterminant();
	p2Mat22 matrix1 = p2Mat22(p2Vec2(rows[1].y, rows[2].y), p2Vec2(rows[2].y, rows[2].z));
	p2Mat22 matrix2 = p2Mat22(p2Vec2(-1 * rows[0].y, -1 * rows[2].y), p2Vec2(-1 * rows[0].z, -1 * rows[2].z));
	p2Mat22 matrix3 = p2Mat22(p2Vec2(rows[0].y,rows[1].y), p2Vec2(rows[0].z,rows[2].y));

	p2Mat22 matrix4 = p2Mat22(p2Vec2(rows[0].y, rows[0].z), p2Vec2(rows[2].y, rows[2].z));
	p2Mat22 matrix5 = p2Mat22(p2Vec2(rows[0].x, rows[0].z), p2Vec2(rows[0].z,rows[2].z));
	p2Mat22 matrix6 = p2Mat22(p2Vec2(rows[0].x, rows[0].y), p2Vec2(rows[0].z, rows[2].y));

	p2Mat22 matrix7 = p2Mat22(p2Vec2(rows[0].y, rows[0].z), p2Vec2(rows[1].y, rows[2].y));
	p2Mat22 matrix8 = p2Mat22(p2Vec2(-1*rows[0].x, -1 * rows[0].z), p2Vec2(-1 * rows[0].y, -1 * rows[2].y));
	p2Mat22 matrix9 = p2Mat22(p2Vec2(rows[0].x, rows[0].y), p2Vec2(rows[0].y, rows[1].y));

	float x1 = (matrix1.rows[0].x*matrix1.rows[1].y) - (matrix1.rows[0].y*matrix1.rows[0].y);
	float y1 = (matrix2.rows[0].x*matrix2.rows[1].y) - (matrix2.rows[0].y*matrix2.rows[0].y);
	float z1=(matrix3.rows[0].x*matrix3.rows[1].y) - (matrix3.rows[0].y*matrix3.rows[0].y);

	float x2 = (matrix4.rows[0].x*matrix4.rows[1].y) - (matrix4.rows[0].y*matrix4.rows[0].y);
	float y2 = (matrix5.rows[0].x*matrix5.rows[1].y) - (matrix5.rows[0].y*matrix5.rows[0].y);
	float z2 = (matrix6.rows[0].x*matrix6.rows[1].y) - (matrix6.rows[0].y*matrix6.rows[0].y);

	float x3 = (matrix7.rows[0].x*matrix7.rows[1].y) - (matrix7.rows[0].y*matrix7.rows[0].y);
	float y3 = (matrix8.rows[0].x*matrix8.rows[1].y) - (matrix8.rows[0].y*matrix8.rows[0].y);
	float z3 = (matrix9.rows[0].x*matrix9.rows[1].y) - (matrix9.rows[0].y*matrix9.rows[0].y);

	return p2Mat33(p2Vec3(x1*multiplicator,y1*multiplicator,z1*multiplicator), p2Vec3(x2*multiplicator, y2*multiplicator, z2*multiplicator), p2Vec3(x3*multiplicator, y3*multiplicator, z3*multiplicator));

}

float p2Mat33::GetDeterminant()
{
	return (rows[0].x+rows[1].y+rows[2].z)+(rows[0].y + rows[1].z + rows[2].x)+(rows[0].z + rows[1].x + rows[2].y)+(rows[0].x-rows[1].y-rows[2].z)+(rows[0].y - rows[1].z - rows[2].x)+(rows[0].z - rows[1].x - rows[2].y);
}
