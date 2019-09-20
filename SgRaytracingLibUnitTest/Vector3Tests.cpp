#include "CppUnitTest.h"
#include "Vector3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SgRaytracingLibUnitTest
{		
	TEST_CLASS(Vector3UnitTests)
	{
	public:
		
		TEST_METHOD(TestDefaultConstructor)
		{
			Vector3 v;
			Assert::AreEqual(v.x, .0f);
			Assert::AreEqual(v.y, .0f);
			Assert::AreEqual(v.z, .0f);
		}

		TEST_METHOD(TestConstructor)
		{
			Vector3 v(10.0f, 5.0f, -3.2f);
			Assert::AreEqual(v.x, 10.0f);
			Assert::AreEqual(v.y, 5.0f);
			Assert::AreEqual(v.z, -3.2f);
		}

		TEST_METHOD(TestCopyConstructor)
		{
			Vector3 v1(1, 5, 6);
			Vector3 vCopy(v1);
			Assert::AreEqual(vCopy.x, 1.0f);
			Assert::AreEqual(vCopy.y, 5.0f);
			Assert::AreEqual(vCopy.z, 6.0f);
		}

		TEST_METHOD(TestPlusOperator)
		{
			Vector3 v1(1, 5, 6);
			Vector3 v2(6, 5, 1);
			Vector3 s = v1 + v2;
			Assert::AreEqual(v1.x, 1.0f);
			Assert::AreEqual(v1.y, 5.0f);
			Assert::AreEqual(v1.z, 6.0f);
			Assert::AreEqual(v2.x, 6.0f);
			Assert::AreEqual(v2.y, 5.0f);
			Assert::AreEqual(v2.z, 1.0f);
			Assert::AreEqual(s.x, 7.0f);
			Assert::AreEqual(s.y, 10.0f);
			Assert::AreEqual(s.z, 7.0f);
		}

		TEST_METHOD(TestMinusOperator)
		{
			Vector3 v1(1, 5, 6);
			Vector3 v2(6, 5, 1);
			Vector3 m = v1 - v2;
			Assert::AreEqual(v1.x, 1.0f);
			Assert::AreEqual(v1.y, 5.0f);
			Assert::AreEqual(v1.z, 6.0f);
			Assert::AreEqual(v2.x, 6.0f);
			Assert::AreEqual(v2.y, 5.0f);
			Assert::AreEqual(v2.z, 1.0f);
			Assert::AreEqual(m.x, -5.0f);
			Assert::AreEqual(m.y, 0.0f);
			Assert::AreEqual(m.z, 5.0f);
		}

		TEST_METHOD(TestMinusEqualsOperator)
		{
			Vector3 v1(1, 5, 6);
			Vector3 v2(6, 5, 1);
			v1 -= v2;
			Assert::AreEqual(v1.x, -5.0f);
			Assert::AreEqual(v1.y, 0.0f);
			Assert::AreEqual(v1.z, 5.0f);
			Assert::AreEqual(v2.x, 6.0f);
			Assert::AreEqual(v2.y, 5.0f);
			Assert::AreEqual(v2.z, 1.0f);
		}

		

	};
}