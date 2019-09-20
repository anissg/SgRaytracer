#include "CppUnitTest.h"
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

		TEST_METHOD(RaySingleSphereIntersection)
		{
			Sphere sphere(Vector3(), 100);
			Ray ray(Vector3(0, 0, -150), Vector3(0, 0, 1));

			Assert::IsTrue(ray.Intersect(sphere).has_value());
		}
		
		TEST_METHOD(RayMultipleSpheresIntersection)
		{
			std::vector<Sphere> spheres;
			spheres.push_back(Sphere(Vector3(), 100));
			spheres.push_back(Sphere(Vector3(0, 20, 200), 80));

			Ray ray(Vector3(0, 0, -150), Vector3(0, 0, 1));


			Assert::IsTrue(ray.Intersect(spheres).has_value());
			//Assert::AreEqual(ray.Intersect(spheres).value, 5.0f);
		}

	

	};
}