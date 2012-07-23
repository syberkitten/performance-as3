ActionScript 3 Performance Primitives
=====================================

## News
 - 2012-07-23: Development snapshot of ANE (x86) version. Documentation now out of date; some functions & classes missing; no unit tests yet
 - 2012-07-20: Drafting support for Flash Player through Adobe Alchemy 2
 - 2012-07-20: Baseline functionality almost complete: floating-point array math, vector math, matrix math
 - 2012-07-17: Full rewrite with vectorization (SSE2) and multithreading support underway
 
<br>

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
   - Win32 (ANE, AMD Framewave)
   - Mac OS X (ANE, AMD Framewave)
   - iOS (ANE, Accelerate Framework)
   - Android (ANE, Renderscript)
   - Flash Player (Adobe Alchemy 2, Pixel Bender)
- Math 
   - **Array math, floating-point** (Win32)
   - Array math, integer
   - **Vector math** (Win32)
   - **Matrix math** (Win32)
- Misc
   - Range support
   - Comparisons, masks, select, scatter/gather
- Timers
   - **High-resolution timer** (Win32)
- Algorithms
   - Compression: LZ4, PackBits, PFOR+PFOR-DELTA
   - Hashing: XXH, Murmur3, Wang

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
Please see [the wiki pages](https://github.com/martinkallman/performance-as3/wiki/_pages).

<br><br>


## Developer's notes
 - Compiler (Win32): Visual Studio 2010

<br><br>

## Credits
 - A special thanks to Naoki Shibata, Yann Collet, Thomas Wang