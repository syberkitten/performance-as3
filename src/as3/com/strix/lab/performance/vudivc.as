package com.strix.lab.performance {
    
    public function vudivc( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("DivC_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}