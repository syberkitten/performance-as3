package com.strix.lab.performance {
    
    public function vfpow( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
        PerformanceLibrary.context.call("Pow_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
    }
    
}