package com.strix.lab.as3pp.array {
    
    import com.strix.lab.as3pp.PerformancePrimitives;
    
    
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
        
        /**
         * dstSrc = dstSrc + src
         */
        public static function addi_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "AddI_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dstSrc = dstSrc - src
         */
        public static function subi_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "SubI_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dstSrc = dstSrc * src
         */
        public static function muli_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "MulI_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dstSrc = dstSrc / src
         */
        public static function divi_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "DivI_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dst = dst + (src1*src2)
         */
        public static function muladd_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "MulAdd_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = sin(src)
         */
        public static function sin_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Sin_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = cos(src)
         */
        public static function cos_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Cos_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = tan(src)
         */
        public static function tan_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Tan_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = Asin(src)
         */
        public static function asin_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Asin_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = Acos(src)
         */
        public static function acos_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Acos_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = Atan(src)
         */
        public static function atan_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Atan_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = atan2(src1, src2)
         */
        public static function atan2_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Atan2_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = sqrt(src)
         */
        public static function sqrt_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Sqrt_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = cbrt(src)
         */
        public static function cbrt_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Cbrt_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = exp(src)
         */
        public static function exp_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Exp_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = ln(src)
         */
        public static function ln_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Ln_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = log10(src)
         */
        public static function log10_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Log10_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = pow(src1, src2)
         */
        public static function pow_32f( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Pow_32f",
                dst.data, src1.data, src2.data,
                dst.offset, src1.offset, src2.offset,
                dst.length
            );
        }
        
        /**
         * dst = pow(src, val)
         */
        public static function powc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "PowC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = abs(src)
         */
        public static function abs_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Abs_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dstSrc = min(dstSrc, src)
         */
        public static function minv_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "MinV_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dstSrc = max(dstSrc, src)
         */
        public static function maxv_32f( dstSrc:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "MinV_32f",
                dstSrc.data, src.data,
                dstSrc.offset, src.offset,
                dstSrc.length
            );
        }
        
        /**
         * dst = max(src, val)
         */
        public static function threshltc_32f( dst:Float32Array, src:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "ThreshLTC_32f",
                dst.data, src.data, val,
                dst.offset, src.offset,
                dst.length
            );
        }
        
    }
    
}