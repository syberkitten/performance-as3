package com.strix.lab.performance {
    
    /**
    * dst = asin(src)
    */
    public function vfasin( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Asin_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}