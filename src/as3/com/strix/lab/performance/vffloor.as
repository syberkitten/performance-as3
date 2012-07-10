package com.strix.lab.performance {
    
    /**
    * dst = floor(src)
    */
    public function vffloor( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Floor_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}