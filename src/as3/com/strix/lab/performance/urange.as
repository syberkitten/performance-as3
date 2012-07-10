package com.strix.lab.performance {
    
    /**
     * Selects a range from a Uint32Array
     */
    public function urange( array:Uint32Array, start:uint=0, length:int=-1 ) : Uint32ArrayRange {
        return new Uint32ArrayRange(array, start, length);
    }
    
}