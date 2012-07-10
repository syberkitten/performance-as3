package com.strix.lab.performance {
    
    /**
    * dst = pow(src, val)
    */
    public function vfpowc( dst:Float32Array, src:Float32Array, val:Number ) : void {
        PerformanceLibrary.context.call("PowC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}