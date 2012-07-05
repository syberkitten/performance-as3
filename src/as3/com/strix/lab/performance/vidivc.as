package com.strix.lab.performance {
    
    public function vidivc( dst:Int32Array, src:Int32Array, val:int ) : void {
        PerformanceLibrary.context.call("DivC_32i", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}