package com.strix.lab.performance {
    
    public function vixorc( dst:Int32Array, src:Int32Array, val:int ) : void {
        PerformanceLibrary.context.call("XorC_32i", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}