/**
 * @file urlmon-uuid.c
 * Copyright 2012, 2013 MinGW.org project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/* Generate GUIDs for URLMON interfaces */

/* All IIDs defined in this file were extracted from
 * HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Interface\ */

#define INITGUID
#include <basetyps.h>
DEFINE_GUID(IID_IBindHost,0xfc4801a1,0x2ba9,0x11cf,0xa2,0x29,0,0xaa,0,0x3d,0x73,0x52);
DEFINE_GUID(IID_IBindProtocol,0x79eac9cd,0xbaf9,0x11ce,0x8c,0x82,0,0xaa,0,0x4b,0xa9,0xb);
DEFINE_GUID(IID_IBindStatusCallback,0x79eac9c1,0xbaf9,0x11ce,0x8c,0x82,0,0xaa,0,0x4b,0xa9,0xb);
DEFINE_GUID(IID_IBindStatusCallbackMsg,0x79eac9cb,0xbaf9,0x11ce,0x8c,0x82,0,0xaa,0,0x4b,0xa9,0xb);
DEFINE_GUID(IID_IBinding,0x79eac9c0,0xbaf9,0x11ce,0x8c,0x82,0,0xaa,0,0x4b,0xa9,0xb);
DEFINE_GUID(IID_IAuthenticate,0x79eac9d0,0xbaf9,0x11ce,0x8c,0x82,0,0xaa,0,0x4b,0xa9,0xb);
