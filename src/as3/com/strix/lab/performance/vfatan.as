package com.strix.lab.performance {
    
    /**
    * dst = atan(src)
    */
    public function vfatan( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Atan_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}