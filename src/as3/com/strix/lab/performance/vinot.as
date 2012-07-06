package com.strix.lab.performance {
    
    public function vinot( dst:Float32Array, src:Float32Array ) : void {
        PerformanceLibrary.context.call("Not_32i", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}