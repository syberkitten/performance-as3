package com.strix.lab.performance {
    
    /**
     * dst = val
     */
    public function viset( dst:Int32ArraySlice, val:Number ) : void {
        var dstArray : Int32Array = dst.array

        PerformanceLibrary.context.call(
            "Set_32i",
            dstArray.data,
            val,
            dstArray.offset + dst.start*4,
            dst.length
        );
    }
    
}