package com.strix.lab.performance {
    
    /**
     * dst = sqrt(src)
     */
    public function vfsqrt( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Sqrt_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}