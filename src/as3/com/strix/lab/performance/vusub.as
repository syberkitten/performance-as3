package com.strix.lab.performance {
    
    public function vusub( dst:Uint32Array, src1:Uint32Array, src2:Uint32Array ) : void {
        PerformanceLibrary.context.call("Sub_32u", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
    }
    
}