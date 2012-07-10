package com.strix.lab.performance {
    
    /**
    * dst = ceil(src)
    */
    public function vfceil( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Ceil_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}