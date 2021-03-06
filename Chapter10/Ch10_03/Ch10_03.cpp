//------------------------------------------------
//               Ch10_03.cpp
//------------------------------------------------

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <string>
#include "YmmVal.h"

using namespace std;

extern "C" void Avx2ZeroExtU8_U16_(YmmVal*a, YmmVal b[2]);
extern "C" void Avx2ZeroExtU8_U32_(YmmVal*a, YmmVal b[4]);
extern "C" void Avx2SignExtI16_I32_(YmmVal*a, YmmVal b[2]);
extern "C" void Avx2SignExtI16_I64_(YmmVal*a, YmmVal b[4]);

const string c_Line(80, '-');

void Avx2ZeroExtU8_U16(void)
{
    alignas(32) YmmVal a;
    alignas(32) YmmVal b[2];

    for (int i = 0; i < 32; i++)
        a.m_U8[i] = (uint8_t)(i * 8);

    Avx2ZeroExtU8_U16_(&a, b);

    cout << "\nResults for Avx2ZeroExtU8_U16_\n";
    cout << c_Line << '\n';

    cout << "a (0:15):   " << a.ToStringU8(0) << '\n';
    cout << "a (16:31):  " << a.ToStringU8(1) << '\n';
    cout << '\n';
    cout << "b (0:7):    " << b[0].ToStringU16(0) << '\n';
    cout << "b (8:15):   " << b[0].ToStringU16(1) << '\n';
    cout << "b (16:23):  " << b[1].ToStringU16(0) << '\n';
    cout << "b (24:31):  " << b[1].ToStringU16(1) << '\n';
}

void Avx2ZeroExtU8_U32(void)
{
    alignas(32) YmmVal a;
    alignas(32) YmmVal b[4];

    for (int i = 0; i < 32; i++)
        a.m_U8[i] = (uint8_t)(255 - i * 8);

    Avx2ZeroExtU8_U32_(&a, b);

    cout << "\nResults for Avx2ZeroExtU8_U32_\n";
    cout << c_Line << '\n';

    cout << "a (0:15):   " << a.ToStringU8(0) << '\n';
    cout << "a (16:31):  " << a.ToStringU8(1) << '\n';
    cout << '\n';
    cout << "b (0:3):    " << b[0].ToStringU32(0) << '\n';
    cout << "b (4:7):    " << b[0].ToStringU32(1) << '\n';
    cout << "b (8:11):   " << b[1].ToStringU32(0) << '\n';
    cout << "b (12:15):  " << b[1].ToStringU32(1) << '\n';
    cout << "b (16:19):  " << b[2].ToStringU32(0) << '\n';
    cout << "b (20:23):  " << b[2].ToStringU32(1) << '\n';
    cout << "b (24:27):  " << b[3].ToStringU32(0) << '\n';
    cout << "b (28:31):  " << b[3].ToStringU32(1) << '\n';
}

void Avx2SignExtI16_I32()
{
    alignas(32) YmmVal a;
    alignas(32) YmmVal b[2];

    for (int i = 0; i < 16; i++)
        a.m_I16[i] = (int16_t)(-32768 + i * 4000);

    Avx2SignExtI16_I32_(&a, b);

    cout << "\nResults for Avx2SignExtI16_I32_\n";
    cout << c_Line << '\n';

    cout << "a (0:7):    " << a.ToStringI16(0) << '\n';
    cout << "a (8:15):   " << a.ToStringI16(1) << '\n';
    cout << '\n';
    cout << "b (0:3):    " << b[0].ToStringI32(0) << '\n';
    cout << "b (4:7):    " << b[0].ToStringI32(1) << '\n';
    cout << "b (8:11):   " << b[1].ToStringI32(0) << '\n';
    cout << "b (12:15):  " << b[1].ToStringI32(1) << '\n';
}

void Avx2SignExtI16_I64()
{
    alignas(32) YmmVal a;
    alignas(32) YmmVal b[4];

    for (int i = 0; i < 16; i++)
        a.m_I16[i] = (int16_t)(32767 - i * 4000);

    Avx2SignExtI16_I64_(&a, b);

    cout << "\nResults for Avx2SignExtI16_I64_\n";
    cout << c_Line << '\n';

    cout << "a (0:7):    " << a.ToStringI16(0) << '\n';
    cout << "a (8:15):   " << a.ToStringI16(1) << '\n';
    cout << '\n';
    cout << "b (0:1):    " << b[0].ToStringI64(0) << '\n';
    cout << "b (2:3):    " << b[0].ToStringI64(1) << '\n';
    cout << "b (4:5):    " << b[1].ToStringI64(0) << '\n';
    cout << "b (6:7):    " << b[1].ToStringI64(1) << '\n';
    cout << "b (8:9):    " << b[2].ToStringI64(0) << '\n';
    cout << "b (10:11):  " << b[2].ToStringI64(1) << '\n';
    cout << "b (12:13):  " << b[3].ToStringI64(0) << '\n';
    cout << "b (14:15):  " << b[3].ToStringI64(1) << '\n';
}

int main()
{
    Avx2ZeroExtU8_U16();
    Avx2ZeroExtU8_U32();
    Avx2SignExtI16_I32();
    Avx2SignExtI16_I64();
    return 0;
}
