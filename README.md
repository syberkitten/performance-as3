ActionScript 3 Performance Primitives
=====================================

## Introduction
This is an experimental library for ActionScript 3 geared towards high-performance math, and is losely modeled on the Intel Performance Primitives library.

Please note that this project is in pre-alpha, and should not be used in production. Its purpose is to investigate the feasibility and usefulness of such a library, and gauge the community's interest.

This library is intended to be used in tandem with the (reintroduced) domainMemory opcodes in the upcoming runtime release.

Depending on platform, function and number of elements, a speed-up of 2-10x can be achieved as compared to native Flash Player math with `Vector.<Number>`.


## Features and roadmap

- Target platforms
   - Win32 (AIR native extension)
   - Mac OS X (AIR native extension)
   - iOS (AIR native extension)
   - Android (AIR native extension)
   - Flash Player (Adobe Alchemy, Pixel Bender)
- Single-precision array math
   - Implemented ([Win32](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math))
- Support functions
   - In development (Win32)
- Integer array math
   - Planned
- Vector and matrix math
   - Planned
- Double-precision array math
   - Depending on community response
- Compression algorithms
   - Depending on community response
- Data structures and STL containers
   - Depending on feasibility


## Usage
1. Create a new ActionScript project using the AIR 3.1 SDK
2. Project properties > ActionScript Build Path > Native Extensions
3. Add the .ane file from the /bin folder. Close the dialog
4. Project > Export release build
5. Choose Signed native installer
6. Create build

```actionscript
var dst  : Float32Array = new Float32Array(4),
    src1 : Float32Array = new Float32Array(4),
    src2 : Float32Array = new Float32Array(4);

//This will be taken care of with the planned support functions and domainMemory
src1.data.position = src1.offset;
src2.data.position = src2.offset;

for( var i : uint = 0; i < 4; i++ ) {
    src1.data.writeFloat(123.4);
    src2.data.writeFloat(234.5);
}
    
//Vectorized add
vfadd(dst, src1, src2);

dst.data.position = dst.offset;
trace(dst.data.readFloat());

//You MUST call this or the OS will be sad
PerformanceLibrary.dispose();
```

## Documentation
 - [Single-precision array math](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math)

## Developer's notes
 - Currently all transcendental functions are scalar. Will investigate moving to SSE2 variants