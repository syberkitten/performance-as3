package com.strix.lab.performance {
    
    /**
     * dst = val - src
     */
    public function vusubcr( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("SubCRev_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}