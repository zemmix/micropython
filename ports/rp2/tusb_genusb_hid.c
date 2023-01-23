
// ****************************************************************************
// *                                                                          *
// *    Auto-created by 'genusb'                                              *
// *                                                                          *
// ****************************************************************************

// The MIT License (MIT)
//
// Copyright 2021, "Hippy"
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

// ****************************************************************************
// *                                                                          *
// *    HID Glue                                                              *
// *                                                                          *
// ****************************************************************************

void GenUsb_Hid_SendKeyboardReport(uint8_t modifier, uint8_t keycode) {
    if (keycode == 0) {
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, 0, NULL);
    } else {
        uint8_t payload[6] = { 0 };
        payload[0] = keycode;
        tud_hid_keyboard_report(REPORT_ID_KEYBOARD, modifier, payload);
    }
}

void GenUsb_Hid_SendMouseReport(int8_t up, int8_t right) {
    tud_hid_mouse_report(REPORT_ID_MOUSE, 0x00, right, -up, 0, 0);
}

// Invoked when received GET_REPORT control request
// Application must fill buffer report's content and return its length.
// Return zero will cause the stack to STALL request

uint16_t tud_hid_get_report_cb(uint8_t           instance,
                               uint8_t           report_id,
                               hid_report_type_t report_type,
                               uint8_t           *buffer,
                               uint16_t          reqlen) {
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) reqlen;
    return 0;
}
// Invoked when received SET_REPORT control request or
// received data on OUT endpoint ( Report ID = 0, Type = 0 )

void tud_hid_set_report_cb(uint8_t           instance,
                           uint8_t           report_id,
                           hid_report_type_t report_type,
                           uint8_t const     *buffer,
                           uint16_t          bufsize) {
    (void) instance;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) bufsize;
}

