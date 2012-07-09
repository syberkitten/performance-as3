package com.strix.lab.performance {
    
    public function vfcopy( dst:Float32ArraySlice, src:Float32ArraySlice ) : void {
        var dstArray : Float32Array = dst.array,
            srcArray : Float32Array = src.array;
        
        if( dst.length != src.length ) {
            throw new Error("Function was called with arrays or ranges of unequal lengths");
        }
        
        PerformanceLibrary.context.call(
            "Copy_32f",
            dstArray.data,
            srcArray.data,
            dstArray.offset + dst.start*4,
            srcArray.offset + src.start*4,
            dst.length,
            src.length
        );
    }
    
}