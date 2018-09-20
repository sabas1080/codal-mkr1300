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
#include "SAMD21DAC.h"
#include "SAMD21PDM.h"
#include "LevelDetector.h"

MKR1300 mkr1300;
SAMD21DMAC dmac;
SAMD21PDM microphone(mkr1300.io.microphoneData, mkr1300.io.microphoneClock, dmac, 10000);
LevelDetector level(microphone.output, 70, 30);

void
onLoud(DeviceEvent)
{
    mkr1300.serial.printf("LOUD\n");
}

void
onQuiet(DeviceEvent)
{
    mkr1300.serial.printf("QUIET\n");
}


int main()
{
    SERIAL_DEBUG->printf("*** MICROPHONE TESTING ***\n\n");

    microphone.enable();

    mkr1300.messageBus.listen(DEVICE_ID_SYSTEM_LEVEL_DETECTOR, LEVEL_THRESHOLD_HIGH, onLoud);
    mkr1300.messageBus.listen(DEVICE_ID_SYSTEM_LEVEL_DETECTOR, LEVEL_THRESHOLD_LOW, onQuiet);

    // All done. Release this fiber back to the scheduler for recycling.
    release_fiber();
}


