package com.strix.lab.as3pp {
    
    public final class ArrayMath {
        
        /**
         * dst = src1 + src2
         */
        public static function add_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Add_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = src1 - src2
         */
        public static function sub_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Sub_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = src1 * src2
         */
        public static function mul_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Mul_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = src1 / src2
         */
        public static function div_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Div_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
    }
    
}