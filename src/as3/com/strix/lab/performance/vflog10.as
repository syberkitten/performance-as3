package com.strix.lab.performance {
    
    /**
    * dst = log10(src)
    */
    public function vflog10( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Log10_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}