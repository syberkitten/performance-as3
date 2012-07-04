package com.strix.lab.performance {
    
    public function vffma( dst:Float32Array, src1:Float32Array, src2:Float32Array, src3:Float32Array ) : void {
        PerformanceLibrary.context.call("FMA_32f", dst.data, src1.data, src2.data, src3.data, dst.offset, src1.offset, src2.offset, src3.offset, dst.length, src1.length, src2.length, src3.length);
    }
    
}