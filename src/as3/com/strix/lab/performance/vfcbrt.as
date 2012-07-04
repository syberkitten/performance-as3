package com.strix.lab.performance {
    
    public function vfcbrt( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Cbrt_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}