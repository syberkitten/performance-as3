ActionScript 3 Performance Primitives
=====================================

## Introduction

This is an experimental library for ActionScript 3 geared towards high-performance math, and is losely modeled on the Intel Performance Primitives library. It is intended for use with games in subsystems that are performance-sensitive, such as graphics, physics and networking.

<br>

### Difference from ActionScript's Math functions
There is a fundamental difference in how AS3PP operates as compared to AVM2's built-in functions exposed through the Math class. In technical terms, in AS3PP you work with what is called the *Structure of Arrays* approach, as opposed to Array of Structures - which is most likely what you are familiar with. These differences are easier to demonstrate with the help of some pseudo-code.


#### Array of Structures
```actionscript
class MadBird {
   public var x : Number;
   public var y : Number;
   
   public function updatePosition( movementX:Number, movementY:Number ) : void {
      this.x += movementX;
      this.y += movementY;
   }
}

//This holds all our birds
var birds : Vector.<MadBird> = new Vector.<MadBird>;

...

//Update every bird's position
for each( var bird : MadBird in birds ) {
   bird.updatePosition(5.7, 20.1);
}
```


<br>


#### Structure of Arrays
```actionscript
class MadBirds {
   public var x : Vector.<Number>;
   public var y : Vector.<Number>;
   private var birdCount : uint;

   public function updatePositions( movementX:Vector.<Number>, movementY:Vector.<Number> ) : void {
      for( var i : uint = 0; i < birdCount; i++ ) {
         this.x[i] += movementX[i];
         this.y[i] += movementY[i];
      }
   }
}

//This holds all our birds
var birds : MadBirds = new MadBirds;

//These hold position updates
var movementX : Vector.<Number>;
var movementY : Vector.<Number>;

...

//Update every bird's position
birds.updatePositions(movementX, movementY);
```


<br>


### Data-oriented design
This slightly different approach usually runs under the banner of a paradigm called *Data-oriented design*, where, for performance reasons, we make data layout a first-class concern. This allows us to make a number of optimizations, since we always operate on contiguous runs of the same attribute (see *Implementation* below for details).

If you are interested in further material on DoD, you can start with the following resources:
 - [Data-oriented design](http://gamesfromwithin.com/data-oriented-design) (Or why you might be shooting yourself in the foot with OOP)
 - <a href="http://www.slideshare.net/DICEStudio/introduction-to-data-oriented-design" title="Introduction to Data Oriented Design" target="_blank">Introduction to Data Oriented Design</a> on Slideshare by DICE


<br>


### Implementation and intended use
The first variant of the library is implemented as an AIR Native extension using C. In addition to the performance benefits of running as native code, the library makes use of the [SSE2](http://en.wikipedia.org/wiki/SSE2) instruction set wherever possible, which means that a lot of computations can be done in parallel (4 at-a-time on most desktops). 

This being so, this library is targeted mainly at games written for AIR (Windows, OS X, iOS, Android), and not the Flash Player for the browser. However, depending on the nature of the upcoming domainMemory opcodes and Adobe Alchemy release, there is a possibility that a second variant will be maintained for the Flash Player that uses an as-of-yet undecided mix of Adobe Alchemy, domainMemory and Pixel Bender.


<br>


### domainMemory and (no) license issues
The ANE (native extension) version of the library *does not* depend on the use of domainMemory opcodes - however, this will by far be the fastest way to access results from computations, as AS3PP works with ByteArrays.

Adobe will not require you to purchase a license for the use of domainMemory and/or Stage3D in AIR applications. As for applications running in the Flash Player, this depends on your income. This may or may not apply to the Flash Player version of the library to begin with, depending on which constellation of technologies is chosen for this sub-project.

<br><br>

## Features and roadmap

- Target platforms
   - Win32 (ANE)
   - Mac OS X (ANE)
   - iOS (ANE, Accelerate Framework)
   - Android (ANE)
   - Flash Player (Adobe Alchemy, Pixel Bender)
- Math 
   - **Single-precision array math** (Implemented, Win32)
   - **Integer array arithmetic** (Implemented, Win32)
   - **Integer array bitwise functions** (Implemented, Win32)
   - Vector and matrix math (Planned)
   - Double-precision array math (Depending on community response)
- Misc
   - **Support functions** (Implemented, Win32)
   - **Range support** (Implemented, Win32)
   - Comparisons, masks, select (In development)
- Timers
   - **High-resolution timer** (Implemented, Win32)
- Algorithms
   - Compression: LZ4 (Planned), PackBits (Planned), PFOR+PFOR-DELTA (Planned)
   - **Hashing:** **XXH** (Implemented, Win32), **Wang** (Implemented, Win32) 
- Data structures and containers (Depending on feasibility)

<br><br>

## Usage
Please read the instructions for [installing, upgrading & troubleshooting](https://github.com/martinkallman/performance-as3/wiki/Installing,-upgrading-and-managing-faulty-state) to add the extension to your project.

```actionscript
class MadBirds {
   public var x : Float32Array;
   public var y : Float32Array;
   private var birdCount : uint;

   public function updatePositions( movementX:Float32Array, movementY:Float32Array ) : void {
      //x = movementX + x
      vfadd(x, movementX, x);
      //y = movementY + y
      vfadd(y, movementY, y);
   }
}

//This holds all our birds
var birds : MadBirds = new MadBirds;

//These hold position updates
var movementX : Float32Array;
var movementY : Float32Array;

...

//Update every bird's position
birds.updatePositions(movementX, movementY);
```

<br><br>

## Documentation
General
 - [Installing, upgrading & troubleshooting](https://github.com/martinkallman/performance-as3/wiki/Installing,-upgrading-and-managing-faulty-state)
 - [Data types](https://github.com/martinkallman/performance-as3/wiki/Data-types)
 - [Function naming](https://github.com/martinkallman/performance-as3/wiki/Function-naming)
 - [Ranges](https://github.com/martinkallman/performance-as3/wiki/Ranges)

Reference
 - Math
    - [Single-precision array math](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math)
    - [Integer array arithmetic](https://github.com/martinkallman/performance-as3/wiki/Integer-array-arithmetic)
    - [Integer array bitwise functions](https://github.com/martinkallman/performance-as3/wiki/Integer-array-bitwise-functions)
 - Misc
    - [Support functions](https://github.com/martinkallman/performance-as3/wiki/Support-functions)
    - [Comparison and select functions](https://github.com/martinkallman/performance-as3/wiki/Compare-and-select-functions)
    - [Masks](https://github.com/martinkallman/performance-as3/wiki/Masks)
 - Timer
    - [PerformanceTimer](https://github.com/martinkallman/performance-as3/wiki/PerformanceTimer)
 - Algorithms
    - [Hashing: XXH, Wang](https://github.com/martinkallman/performance-as3/wiki/Algorithms)

<br><br>


## Developer's notes
 - This library requires a SSE2-capable machine
 - Currently all transcendental functions are scalar. Will investigate moving to SSE2 variants
 - To compile with GCC/MinGW, use the following flags in order to benefit from vectorization: `-msse2 -ftree-vectorize`

<br><br>

## Credits
 - A special thanks to Naoki Shibata, Yann Collet, Thomas Wang