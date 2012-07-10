package com.strix.lab.performance {
    
    /**
     * dst = src
     */
    public function vicopy( dst:Int32ArraySlice, src:Int32ArraySlice ) : void {
        var dstArray : Int32Array = dst.array,
            srcArray : Int32Array = src.array;
        
        if( dst.length != src.length ) {
            throw new Error("Function was called with arrays or ranges of unequal lengths");
        }
        
        PerformanceLibrary.context.call(
            "Copy_32i",
            dstArray.data,
            srcArray.data,
            dstArray.offset + dst.start*4,
            srcArray.offset + src.start*4,
            dst.length,
            src.length
        );
    }
    
}