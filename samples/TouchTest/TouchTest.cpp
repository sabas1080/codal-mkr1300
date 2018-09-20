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
#include "TouchSensor.h"

MKR1300 mkr1300;
TouchButton b12(mkr1300.io.d12, mkr1300.touchSensor);
TouchButton b6(mkr1300.io.d6, mkr1300.touchSensor);

void onButton(DeviceEvent e)
{
    if (e.source == ID_PIN_D6)
        mkr1300.serial.printf("D6: ");

    if (e.source == ID_PIN_D12)
        mkr1300.serial.printf("D12: ");

    if (e.value == DEVICE_BUTTON_EVT_DOWN)
        mkr1300.serial.printf("DOWN");

    if (e.value == DEVICE_BUTTON_EVT_UP)
        mkr1300.serial.printf("UP");

    if (e.value == DEVICE_BUTTON_EVT_CLICK)
        mkr1300.serial.printf("CLICK");

    if (e.value == DEVICE_BUTTON_EVT_LONG_CLICK)
        mkr1300.serial.printf("LONG_CLICK");

    if (e.value == DEVICE_BUTTON_EVT_HOLD)
        mkr1300.serial.printf("HOLD");

    if (e.value == DEVICE_BUTTON_EVT_DOUBLE_CLICK)
        mkr1300.serial.printf("DOUBLE_CLICK");

    mkr1300.serial.printf("\r\n");
}

int main()
{
    mkr1300.serial.printf("*** TOUCH TEST ***\n");

    mkr1300.messageBus.listen(ID_PIN_D6, DEVICE_EVT_ANY, onButton);
    mkr1300.messageBus.listen(ID_PIN_D12, DEVICE_EVT_ANY, onButton);

    while(1)
        mkr1300.sleep(1000);
}


