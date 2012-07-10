package com.strix.lab.performance {
    
    /**
     * Casts a Float32Array to a Uint32Array
     */
    public function vfcastu( src:Float32Array, dst:Uint32Array ) : void {
        PerformanceLibrary.context.call("Cast_32f32u", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}