performance-as3
===============

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
   - Flash Player (Adobe Alchemy)
- Single-precision array math
   - Implemented ([Win32](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math))
- Integer array math
   - In development (Win32)
- Vector and matrix math
   - Planned
- Double-precision array math
   - Depending on community response
- Compression algorithms
   - Depending on community response
- Data structures
   - Depending on feasibility