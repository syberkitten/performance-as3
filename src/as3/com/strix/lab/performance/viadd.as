package com.strix.lab.performance {
    
    public function viadd( dst:Int32Array, src1:Int32Array, src2:Int32Array ) : void {
        PerformanceLibrary.context.call("Add_32i", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
    }
    
}