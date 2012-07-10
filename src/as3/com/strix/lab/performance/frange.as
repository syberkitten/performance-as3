package com.strix.lab.performance {
    
    /**
    * Selects a range from a Float32Array
    */
    public function frange( array:Float32Array, start:uint=0, length:int=-1 ) : Float32ArrayRange {
        return new Float32ArrayRange(array, start, length);
    }
    
}