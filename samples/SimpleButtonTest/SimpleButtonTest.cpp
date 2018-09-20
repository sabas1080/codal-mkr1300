/*
The MIT License (MIT)

Copyright (c) 2016 Lancaster University.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MKR1300.h"

MKR1300 mkr1300;

int main()
{
    mkr1300.serial.printf("--POWER ON--\n");

    while(1)
    {
        if (mkr1300.buttonA.isPressed())
            mkr1300.serial.printf("A: on\n");
        else
            mkr1300.serial.printf("A: off\n");

        if (mkr1300.buttonB.isPressed())
            mkr1300.serial.printf("B: on\n");
        else
            mkr1300.serial.printf("B: off\n");

        if (mkr1300.buttonC.isPressed())
            mkr1300.serial.printf("C: on\n");
        else
            mkr1300.serial.printf("C: off\n");
        mkr1300.sleep(1000);
    }
}
