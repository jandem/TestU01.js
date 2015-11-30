#include <unif01.h>
#include <bbattery.h>
#include <emscripten.h>

static double
GetMathRandom()
{
    double d = EM_ASM_DOUBLE({
        return Math.random();
    }, 0);
    return d;
}

void EMSCRIPTEN_KEEPALIVE RunSmallCrushMathRandom()
{
    unif01_Gen* gen = unif01_CreateExternGen01("Math.random()", GetMathRandom);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
}

void EMSCRIPTEN_KEEPALIVE RunCrushMathRandom()
{
    unif01_Gen* gen = unif01_CreateExternGen01("Math.random()", GetMathRandom);
    bbattery_Crush(gen);
    unif01_DeleteExternGen01(gen);
}

void EMSCRIPTEN_KEEPALIVE RunBigCrushMathRandom()
{
    unif01_Gen* gen = unif01_CreateExternGen01("Math.random()", GetMathRandom);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
}
