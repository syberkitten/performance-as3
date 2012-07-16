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
        
        /**
         * dst = src + val
         */
        public static function addc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "AddC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = src - val
         */
        public static function subc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "SubC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = src * val
         */
        public static function mulc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "MulC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = src / val
         */
        public static function divc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "DivC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = val - src
         */
        public static function subcr_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "SubCRev_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = val / src
         */
        public static function divcr_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "DivCRev_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }        
        
    }
    
}