package com.strix.lab.performance {
    
    /**
    * dst = exp(src)
    */
    public function vfexp( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Exp_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}