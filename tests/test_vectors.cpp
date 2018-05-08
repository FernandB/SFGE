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
#include <iostream>
#include "p2vector.h"
#include "SFML\Graphics.hpp"


 void testCross()
{
	// if result is -15 6 5, it works.
	
	p2Vec3 v1 = p2Vec3(1, 0, 3);
	p2Vec3 v2 = p2Vec3(4, 5, 6);
	p2Vec3 r = p2Vec3::Cross(v1, v2);
	std::cout << r.x << " " << r.y << " " << r.z;

}


	

 int main()
 {
	 p2Vec3 a(1.0f, 2.0f, 3.0f);
	 p2Vec3 b(4.0f, 5.0f, 6.0f);
	 
		 p2Vec3::Show(p2Vec3::plus(a, b));
	 p2Vec3::Show(p2Vec3::minus(a, b));
	 std::cout << "Dot product: " << p2Vec3::Dot(a, b) << "\n";
	 p2Vec3::Show(p2Vec3::Cross(a, b));
	 p2Vec3::Show(p2Vec3::Lerp(a, b,0.5f));
	 p2Vec3::Show(p2Vec3::Proj(a, b,0.5f));
	p2Vec3::Show(p2Vec3::Proj(b, a,0.5f));
	 p2Vec3::Show(p2Vec3::Refl(a, b));
	 p2Vec3::Show(p2Vec3::Refl(b, a));
	 std::cout << "Angle between the vectors: " << p2Vec3::AnglesBetween(a,
		 b) << "\n";

	 system("pause");
	 return 0;

 }