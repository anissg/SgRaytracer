#include "CppUnitTest.h"
#include <optional>
#include <vector>
#include "Ray.h"
#include "Sphere.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SgRaytracingLibUnitTest
{
	TEST_CLASS(RayUnitTests)
	{
	public:

		/*-------------------------------------------------------------------------------------------------------------

							   +
				,- ~ ,         +---------------------------------------------------------------->     No intersection
			, '        ' ,     |
		  ,                ,   |                       ,- ~ ,
		 ,                  ,  |                   , '        ' ,
		,                    , |                 ,                ,
		,                    , |                ,                  ,
		,                    , |               ,                    ,
		 ,                  ,  |               ,                    ,
		  ,                ,   |               ,                    ,
			,           , '    |                ,                  ,         ,- ~ ,
			  ' -, _ ,-        |                 ,                ,      , '        ' ,
							   +-------------------X------------X-------X--------------X-------->     Multiple sphere intersection
							   |                     ' -, _ ,-        ,                  ,
							   |                                     ,                    ,
							   |                                     ,                    ,
							   |                                     ,                    ,
							   +--------------------------------------X------------------X------>     Single sphere intersection
							   |                                       ,                ,
							   |                                         ,           , '
							 ,-|~ ,                                        ' -, _ ,-
						 , '   |    ' ,
					   ,       |        ,
					  ,        |         ,
					 ,         |          ,
					 ,         +----------X----------------------------------------------------->     Ray inside sphere
					 ,         |          ,
					  ,        |         ,
					   ,       |        ,
						 ,     |     , '
						   ' -,|_ ,-
							   |
							   |
							   +
		
		---------------------------------------------------------------------------------------------------------------*/

        TEST_METHOD(RayNoIntersection)
        {
            Sphere sphere(Vector3(), 100);
            Ray ray(Vector3(150, 0, -150), Vector3(0, 0, 1));

            Assert::IsFalse(ray.Intersect(sphere).has_value());
        }

		TEST_METHOD(RaySingleSphereIntersection)
		{
			Sphere sphere(Vector3(), 100);
			Ray ray(Vector3(0, 0, -150), Vector3(0, 0, 1));

			Assert::IsTrue(ray.Intersect(sphere).has_value());
		}

        TEST_METHOD(RayMultipleSpheresIntersectionNotAligned)
        {
            std::vector<Sphere> spheres;
            spheres.push_back(Sphere(Vector3(), 100));
            spheres.push_back(Sphere(Vector3(0, 150, 200), 100));

            Ray ray(Vector3(0, 0, -150), Vector3(0, 0, 1));
            std::optional result = ray.Intersect(spheres);

            Assert::IsTrue(result.has_value());
            Assert::AreEqual(result.value_or(-1), 50.0f);
        }

        TEST_METHOD(RayMultipleSpheresIntersectionAligned)
        {
            std::vector<Sphere> spheres;
            spheres.push_back(Sphere(Vector3(), 100));
            spheres.push_back(Sphere(Vector3(0, 10, 200), 50));

            Ray ray(Vector3(0, 0, -150), Vector3(0, 0, 1));
            std::optional result = ray.Intersect(spheres);

            Assert::IsTrue(result.has_value());
            Assert::AreEqual(result.value_or(-1), 50.0f);
        }

        TEST_METHOD(RayInsideSphere)
        {
            Sphere sphere(Vector3(), 100);
            Ray ray(Vector3(0, 0, 0), Vector3(0, 0, 1));

            Assert::IsFalse(ray.Intersect(sphere).has_value());
        }
	

	};
}