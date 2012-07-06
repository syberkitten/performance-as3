ActionScript 3 Performance Primitives
=====================================

## Introduction

This is an experimental library for ActionScript 3 geared towards high-performance math, and is losely modeled on the Intel Performance Primitives library. It is intended for use with games in subsystems that are performance-sensitive, such as graphics, physics and networking.


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
   - Win32 (AIR native extension)
   - Mac OS X (AIR native extension)
   - iOS (AIR native extension)
   - Android (AIR native extension)
   - Flash Player (Adobe Alchemy, Pixel Bender)
- Single-precision array math: Implemented ([Win32](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math))
- Integer array arithmetic: Implemented ([Win32](https://github.com/martinkallman/performance-as3/wiki/Integer-array-arithmetic))
- Integer array bitwise functions: In development [Win32](https://github.com/martinkallman/performance-as3/wiki/Integer-array-bitwise-functions))
- Support functions: In development ([Win32](https://github.com/martinkallman/performance-as3/wiki/Support-functions))
- Vector and matrix math: Planned
- Double-precision array math: Depending on community response
- Compression algorithms: Depending on community response
- Data structures and STL containers: Depending on feasibility

<br><br>

## Usage
Please read the instructions for [installing, upgrading & troubleshooting](https://github.com/martinkallman/performance-as3/wiki/Installing,-upgrading-and-managing-faulty-state) to add the extension to your project.

```actionscript
var dst  : Float32Array = new Float32Array(4),
    src1 : Float32Array = new Float32Array(4),
    src2 : Float32Array = new Float32Array(4);

//This will be changed with the planned support functions and domainMemory
for( var i : uint = 0; i < 4; i++ ) {
    src1[i] = 123.4;
    src2[i] = 234.5;
}
    
//Vectorized add
vfadd(dst, src1, src2);

trace(dst[0]);

//You MUST call this or the OS will be sad
PerformanceLibrary.dispose();
```

<br><br>

## Documentation
General
 - [Function naming](https://github.com/martinkallman/performance-as3/wiki/Function-naming)

Reference
 - [Single-precision array math](https://github.com/martinkallman/performance-as3/wiki/Single-precision-array-math)
 - [Integer array arithmetic](https://github.com/martinkallman/performance-as3/wiki/Integer-array-arithmetic)
 - [Integer array bitwise functions](https://github.com/martinkallman/performance-as3/wiki/Integer-array-bitwise-functions)
 - [Support functions](https://github.com/martinkallman/performance-as3/wiki/Support-functions)
 

<br><br>


## Developer's notes
 - This library requires a SSE2-capable machine
 - Currently all transcendental functions are scalar. Will investigate moving to SSE2 variants