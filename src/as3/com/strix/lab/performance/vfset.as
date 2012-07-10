package com.strix.lab.performance {
    
    /**
    * dst = val
    */
    public function vfset( dst:Float32ArraySlice, val:Number ) : void {
        var dstArray : Float32Array = dst.array;
        
        PerformanceLibrary.context.call(
            "Set_32f",
            dstArray.data,
            val,
            dstArray.offset + dst.start*4,
            dst.length
        );
    }
    
}