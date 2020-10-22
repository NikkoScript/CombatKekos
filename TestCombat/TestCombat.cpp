#include "CppUnitTest.h"
#include "degat.h"
#include "caracteristique.h"
#include "RNGClasse.h"
#include <personnage.h>
#include <abilite.h>
#include <iostream>
#include <coefDegPhys.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCombat
{
	TEST_CLASS(TestDegat)
	{
	public:
		
		TEST_METHOD(testInitDegat0)
		{
			degat* testd;
			testd = new degat();
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::eau));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::feu));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::terre));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::vent));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::ombre));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::perforant));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::impact));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::tranchant));
			delete testd;
			
		}

		TEST_METHOD(testInitDegat3) {
			degat* testd;
			testd = new degat(10, 11, 12);
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::eau));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::feu));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::terre));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::vent));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::ombre));
			Assert::AreEqual(0, testd->getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(10, testd->getdegatphysique(dphysique::perforant));
			Assert::AreEqual(11, testd->getdegatphysique(dphysique::impact));
			Assert::AreEqual(12, testd->getdegatphysique(dphysique::tranchant));
			delete testd;
		}

		TEST_METHOD(testInitDegat6) {
			degat* testd;
			testd = new degat(10, 11, 12, 13, 14, 15);
			Assert::AreEqual(11, testd->getdegatmagique(dmagique::eau));
			Assert::AreEqual(10, testd->getdegatmagique(dmagique::feu));
			Assert::AreEqual(12, testd->getdegatmagique(dmagique::terre));
			Assert::AreEqual(13, testd->getdegatmagique(dmagique::vent));
			Assert::AreEqual(14, testd->getdegatmagique(dmagique::ombre));
			Assert::AreEqual(15, testd->getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::perforant));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::impact));
			Assert::AreEqual(0, testd->getdegatphysique(dphysique::tranchant));
			delete testd;
		}

		TEST_METHOD(testInitDegat9) {
			degat* testd;
			testd = new degat(10, 11, 12, 13, 14, 15, 16, 17, 18); 
			Assert::AreEqual(14, testd->getdegatmagique(dmagique::eau));
			Assert::AreEqual(13, testd->getdegatmagique(dmagique::feu));
			Assert::AreEqual(15, testd->getdegatmagique(dmagique::terre));
			Assert::AreEqual(16, testd->getdegatmagique(dmagique::vent));
			Assert::AreEqual(17, testd->getdegatmagique(dmagique::ombre));
			Assert::AreEqual(18, testd->getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(10, testd->getdegatphysique(dphysique::perforant));
			Assert::AreEqual(11, testd->getdegatphysique(dphysique::impact));
			Assert::AreEqual(12, testd->getdegatphysique(dphysique::tranchant));
			delete testd;
		}

		TEST_METHOD(testoperatoradd) {
			degat a(1, 2, 3, 4, 5, 6, 7, 8, 9);
			degat b(9, 8, 7, 6, 5, 4, 3, 2, 1);
			degat c;
			c = a + b;

			Assert::AreEqual(10, c.getdegatmagique(dmagique::eau));
			Assert::AreEqual(10, c.getdegatmagique(dmagique::feu));
			Assert::AreEqual(10, c.getdegatmagique(dmagique::terre));
			Assert::AreEqual(10, c.getdegatmagique(dmagique::vent));
			Assert::AreEqual(10, c.getdegatmagique(dmagique::ombre));
			Assert::AreEqual(10, c.getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(10, c.getdegatphysique(dphysique::perforant));
			Assert::AreEqual(10, c.getdegatphysique(dphysique::impact));
			Assert::AreEqual(10, c.getdegatphysique(dphysique::tranchant));
		}
		TEST_METHOD(testoperatoraddequa) {
			degat a(1, 2, 3, 4, 5, 6, 7, 8, 9);
			degat b(9, 8, 7, 6, 5, 4, 3, 2, 1);
			a+=b;

			Assert::AreEqual(10, a.getdegatmagique(dmagique::eau));
			Assert::AreEqual(10, a.getdegatmagique(dmagique::feu));
			Assert::AreEqual(10, a.getdegatmagique(dmagique::terre));
			Assert::AreEqual(10, a.getdegatmagique(dmagique::vent));
			Assert::AreEqual(10, a.getdegatmagique(dmagique::ombre));
			Assert::AreEqual(10, a.getdegatmagique(dmagique::lumiere));
			Assert::AreEqual(10, a.getdegatphysique(dphysique::perforant));
			Assert::AreEqual(10, a.getdegatphysique(dphysique::impact));
			Assert::AreEqual(10, a.getdegatphysique(dphysique::tranchant));
		}
	};

	TEST_CLASS(TestRNG) {
		TEST_METHOD(initRNG) {
			RNGClasse* genrng;
			genrng = new RNGClasse();
			Assert::IsTrue((100> genrng->getRNGInt(100)));
			Assert::IsTrue((1.0f > genrng->getfloat()));
		}
	};

	TEST_CLASS(Testabilite) {
		TEST_METHOD(Testcreateabilite) {
			personnage *perso1, *perso2;
			perso1 = new personnage();
			perso2 = new personnage();
			abilite ab;
			
			Assert::AreEqual(5.0f/6.0f, ab.chanceToucher(*perso1, *perso2));

		}
		TEST_METHOD(testdegatinflige) {
			personnage* perso1, * perso2;
			perso1 = new personnage();
			perso2 = new personnage();
			abilite ab(degat(10,0,0),"piercingtruth", 10,1,1);
			Assert::AreEqual(11, ab.degatinflige(*perso1, *perso2));
		}
	};

	TEST_CLASS(TestCOefDegPhysique) {
		TEST_METHOD(testmultlourde) {
			degat perf(2, 0, 0);
			degat impact(0, 2, 0);
			degat tranchant(0, 0, 2);
			int* res = new int[dmagiquetaille];
			for (int k = 0; k < dmagiquetaille; k++)
			{
				res[k] = 0;
			}
			coefDegPhys coef(classeArmure::lourde, res,0);
			Assert::AreEqual(1.8f, coef.multDeg(perf));
			Assert::AreEqual(2.0f, coef.multDeg(impact));
			Assert::AreEqual(1.6f, coef.multDeg(tranchant));

		}

		TEST_METHOD(testmultlegere) {
			degat perf(2, 0, 0);
			degat impact(0, 2, 0);
			degat tranchant(0, 0, 2);
			int* res = new int[dmagiquetaille];
			for (int k = 0; k < dmagiquetaille; k++)
			{
				res[k] = 0;
			}
			coefDegPhys coef(classeArmure::legere,res,0);
			Assert::AreEqual(2.2f, coef.multDeg(perf));
			Assert::AreEqual(2.0f, coef.multDeg(impact));
			Assert::AreEqual(2.4f, coef.multDeg(tranchant));

		}
		TEST_METHOD(testmultmoyenne) {
			degat perf(2, 0, 0);
			degat impact(0, 2, 0);
			degat tranchant(0, 0, 2);
			int* res = new int[dmagiquetaille];
			for (int k = 0; k < dmagiquetaille; k++)
			{
				res[k] = 0;
			}
			coefDegPhys coef(classeArmure::moyenne,res,0);
			Assert::AreEqual(2.2f, coef.multDeg(perf));
			Assert::AreEqual(1.8f, coef.multDeg(impact));
			Assert::AreEqual(2.0f, coef.multDeg(tranchant));
		}
	};
}
