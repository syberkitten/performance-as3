package com.strix.lab.performance {
    
    public function vuset( dst:Uint32ArraySlice, val:Number ) : void {
        var dstArray : Uint32Array = dst.array;
        
        PerformanceLibrary.context.call(
            "Set_32u",
            dstArray.data,
            val,
            dstArray.offset + dst.start*4,
            dst.length
        );
    }
    
}