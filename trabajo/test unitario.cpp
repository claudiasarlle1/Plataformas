#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            auto carta1= 2;
            auto carta2 = 3;
            int result = 5;
        }
         TEST_METHOD(TestMethod2)
        {
           int partidas_ganadas = 0;{
            auto suma_cartas_usuario=17;
            auto suma_cartas_casa= 12;

           }
              int partidas_ganadas_usuario = 1;
        }
         TEST_METHOD(TestMethod3)
        {
            auto capital_usuario=100;
            auto cantidad_apostada_usuario= 20;
            int ganadas = 120;
        }
    };
}