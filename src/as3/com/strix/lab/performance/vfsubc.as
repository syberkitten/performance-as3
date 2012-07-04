package com.strix.lab.performance {
    
    public function vfsubc( dst:Float32Array, src:Float32Array, val:Number ) : void {
        PerformanceLibrary.context.call("SubC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}