package com.strix.lab.performance {
    
    /**
     * dst = src, src = 0
     */
    public function vumove( dst:Uint32ArraySlice, src:Uint32ArraySlice ) : void {
        var dstArray : Uint32Array = dst.array,
            srcArray : Uint32Array = src.array;
        
        if( dst.length != src.length ) {
            throw new Error("Function was called with arrays or ranges of unequal lengths");
        }
        
        PerformanceLibrary.context.call(
            "Move_32u",
            dstArray.data,
            srcArray.data,
            dstArray.offset + dst.start*4,
            srcArray.offset + src.start*4,
            dst.length,
            src.length
        );
    }
    
}