package com.strix.lab.performance {
    
    /**
     * Casts a Uint32Array to an Int32Array
     */
    public function vucasti( src:Uint32Array, dst:Int32Array ) : void {
        PerformanceLibrary.context.call("Cast_32u32i", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}