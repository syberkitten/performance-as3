package com.strix.lab.performance {
    
    public function vursh( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("Rsh_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}