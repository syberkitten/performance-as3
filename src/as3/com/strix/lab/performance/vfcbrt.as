package com.strix.lab.performance {
    
    /**
    * dst = cbrt(src)
    */
    public function vfcbrt( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Cbrt_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}