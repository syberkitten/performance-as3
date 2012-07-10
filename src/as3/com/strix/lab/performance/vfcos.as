package com.strix.lab.performance {
    
    /**
    * dst = cos(src)
    */
    public function vfcos( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Cos_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}