package com.strix.lab.performance {
    
    /**
     * dst = val - src
     */
    public function visubcr( dst:Int32Array, src:Int32Array, val:int ) : void {
        PerformanceLibrary.context.call("SubCRev_32i", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}