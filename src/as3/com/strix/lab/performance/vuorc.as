package com.strix.lab.performance {
    
    /**
     * dst = src | val
     */
    public function vuorc( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("OrC_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}