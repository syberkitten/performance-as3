package com.strix.lab.performance {
    
    public function urange( array:Uint32Array, start:uint=0, length:int=-1 ) : Uint32ArrayRange {
        return new Uint32ArrayRange(array, start, length);
    }
    
}