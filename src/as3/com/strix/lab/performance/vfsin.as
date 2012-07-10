package com.strix.lab.performance {
    
    /**
    * dst = sin(src)
    */
    public function vfsin( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Sin_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}