package com.strix.lab.performance {
    
    /**
    * dst = src % val
    */
    public function vfmodc( dst:Float32Array, src:Float32Array, val:Number ) : void {
        PerformanceLibrary.context.call("ModC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}