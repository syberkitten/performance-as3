package com.strix.lab.performance {
    
    /**
     * Casts an Int32Array to a Uint32Array
     */
    public function vicastu( src:Int32Array, dst:Uint32Array ) : void {
        PerformanceLibrary.context.call("Cast_32i32u", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}