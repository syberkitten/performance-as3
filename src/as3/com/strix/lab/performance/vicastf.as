package com.strix.lab.performance {
    
    /**
     * Casts an Int32Array to a Float32Array
     */
    public function vicastf( src:Int32Array, dst:Float32Array ) : void {
        PerformanceLibrary.context.call("Cast_32i32f", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}