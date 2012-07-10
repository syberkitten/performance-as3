package com.strix.lab.performance {
    
    /**
     * Casts a Uint32Array to a Float32Array
     */
    public function vucastf( src:Uint32Array, dst:Float32Array ) : void {
        PerformanceLibrary.context.call("Cast_32u32f", dst.data, src.data, dst.offset, src.offset, dst.length);
    }
    
}