package com.strix.lab.performance {
    
    /**
    * dst = acos(src)
    */
    public function vfacos( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Acos_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}