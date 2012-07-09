package com.strix.lab.performance {
    
    public function irange( array:Int32Array, start:uint=0, length:int=-1 ) : Int32ArrayRange {
        return new Int32ArrayRange(array, start, length);
    }
    
}