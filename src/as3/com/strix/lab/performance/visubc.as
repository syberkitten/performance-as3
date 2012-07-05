package com.strix.lab.performance {
    
    public function visubc( dst:Int32Array, src:Int32Array, val:int ) : void {
        PerformanceLibrary.context.call("SubC_32i", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}