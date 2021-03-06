//------------------------------------------------
//               Ch11_04.cpp
//------------------------------------------------

#include "stdafx.h"
#include <cstdint>
#include <iostream>
#include <iomanip>

using namespace std;

extern "C" void GprCountZeroBits_(uint32_t x, uint32_t* lzcnt, uint32_t* tzcnt);
extern "C" uint32_t GprBextr_(uint32_t x, uint8_t start, uint8_t length);
extern "C" uint32_t GprAndNot_(uint32_t x, uint32_t y);

void GprCountZeroBits(void)
{
    const int n = 5;
    uint32_t x[n] = { 0x001000008, 0x00008000, 0x8000000, 0x00000001, 0 };

    cout << "\nResults for AvxGprCountZeroBits\n";

    for (int i = 0; i < n; i++)
    {
        uint32_t lzcnt, tzcnt;

        GprCountZeroBits_(x[i], &lzcnt, &tzcnt);

        cout << setfill('0') << hex;
        cout << "x: 0x" << setw(8) << x[i] << "  ";
        cout << setfill(' ') << dec;
        cout << "lzcnt: " << setw(3) << lzcnt << "  ";
        cout << "tzcnt: " << setw(3) << tzcnt << '\n';
    }
}

void GprExtractBitField(void)
{
    const int n = 3;
    uint32_t x[n] = { 0x12345678, 0x80808080, 0xfedcba98 };
    uint8_t start[n] = { 4, 7, 24 };
    uint8_t len[n] = { 16, 9, 8 };

    cout << "\nResults for GprExtractBitField\n";

    for (int i = 0; i < n; i++)
    {
        uint32_t bextr = GprBextr_(x[i], start[i], len[i]);

        cout << setfill('0') << hex;
        cout << "x: 0x" << setw(8) << x[i] << "  ";

        cout << setfill(' ') << dec;
        cout << "start: " << setw(3) << (uint32_t)start[i] << "  ";
        cout << "len:   " << setw(3) << (uint32_t)len[i] << "  ";
        cout << setfill('0') << hex;
        cout << "bextr: 0x" << setw(8) << bextr << '\n';
    }
}

void GprAndNot(void)
{
    const int n = 3;
    uint32_t x[n] = { 0xf000000f, 0xff00ff00, 0xaaaaaaaa };
    uint32_t y[n] = { 0x12345678, 0x12345678, 0xffaa5500 };

    cout << "\nResults for GprAndNot\n";

    for (int i = 0; i < n; i++)
    {
        uint32_t andn = GprAndNot_(x[i], y[i]);

        cout << setfill('0') << hex;
        cout << "x: 0x" << setw(8) << x[i] << "  ";
        cout << "y: 0x" << setw(8) << y[i] << "  ";
        cout << "andn: 0x" << setw(8) << andn << '\n';
    }
}

int main()
{
    GprCountZeroBits();
    GprExtractBitField();
    GprAndNot();
    return 0;
}
