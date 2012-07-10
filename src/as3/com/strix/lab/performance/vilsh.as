package com.strix.lab.performance {
    
    /**
     * dst = src << val
     */
    public function vilsh( dst:Int32Array, src:Int32Array, val:int ) : void {
        PerformanceLibrary.context.call("Lsh_32i", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
    }
    
}