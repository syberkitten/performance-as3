package com.strix.lab.performance {
    
    public function vulsh( dst:Uint32Array, src:Uint32Array, val:uint ) : void {
        PerformanceLibrary.context.call("Lsh_32u", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}