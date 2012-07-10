package com.strix.lab.performance {
    
    /**
     * dst = tan(src)
     */
    public function vftan( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Tan_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}