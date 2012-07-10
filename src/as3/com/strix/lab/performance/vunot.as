package com.strix.lab.performance {
    
    /**
     * dst = ~src
     */
    public function vunot( dst:Uint32Array, src:Uint32Array ) : void {
        PerformanceLibrary.context.call("Not_32u", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
    }
    
}