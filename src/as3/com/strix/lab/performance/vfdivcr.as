package com.strix.lab.performance {
    
    /**
    * dst = val / src
    */
    public function vfdivcr( dst:Float32Array, src:Float32Array, val:Number ) : void {
        PerformanceLibrary.context.call("DivCRev_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}