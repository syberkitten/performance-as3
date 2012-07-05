package com.strix.lab.performance {
    
    public function vumodc( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("ModC_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}