package com.strix.lab.performance {
    
    public function vuaddc( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("AddC_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}