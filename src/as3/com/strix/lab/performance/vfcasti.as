package com.strix.lab.performance {
    
    /**
     * Casts a Float32Array to an Int32Array
     */
    public function vfcasti( src:Float32Array, dst:Int32Array ) : void {
        PerformanceLibrary.context.call("Cast_32f32i", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}