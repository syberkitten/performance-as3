package com.strix.lab.performance {
    
    /**
     * dst = abs(src)
     */
    public function vfabs( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Abs_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}