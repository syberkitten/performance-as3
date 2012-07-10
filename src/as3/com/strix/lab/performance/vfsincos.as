package com.strix.lab.performance {
    
    /**
     * dstsin = sin(src), dstcos = cos(src)
     */
    public function vfsincos( dstsin:Float32Array, dstcos:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("SinCos_32f", dstsin.data, dstcos.data, src.data, dstsin.offset, dstcos.offset, src.offset, dstsin.length, dstcos.length, src.length);
    }
    
}