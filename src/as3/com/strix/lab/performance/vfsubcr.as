package com.strix.lab.performance {
    
    /**
     * dst = val - src
     */
    public function vfsubcr( dst:Float32Array, src:Float32Array, val:Number ) : void {
        PerformanceLibrary.context.call("SubCRev_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}