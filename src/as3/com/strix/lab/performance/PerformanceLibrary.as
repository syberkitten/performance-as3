package com.strix.lab.performance {
    
    import flash.events.EventDispatcher;
    import flash.events.IEventDispatcher;
    import flash.external.ExtensionContext;
    import flash.utils.ByteArray;
    
    public class PerformanceLibrary {
        
        public static var context : ExtensionContext;
        
        {
            context = ExtensionContext.createExtensionContext("PerformanceLib", null);
        }
        
        public static function dispose() : void {
            context.dispose();
        }
        
        /*
        public static function getMemoryAddress( byteArray:ByteArray ) : uint {
            return context.call("GetMemoryAddress", byteArray) as uint;
        }
       
        public static function vfadd( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Add_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfaddc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("AddC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfsub( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Sub_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfsubc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("SubC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfsubcr( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("SubCRev_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfmul( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Mul_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfmulc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("MulC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfdiv( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Div_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfdivc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("DivC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfdivcr( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("DivCRev_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfsin( dst:Float32Array, src:Float32Array ) : void {
            context.call("Sin_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfcos( dst:Float32Array, src:Float32Array ) : void {
            context.call("Cos_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vftan( dst:Float32Array, src:Float32Array ) : void {
            context.call("Tan_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfasin( dst:Float32Array, src:Float32Array ) : void {
            context.call("Asin_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfacos( dst:Float32Array, src:Float32Array ) : void {
            context.call("Acos_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfatan( dst:Float32Array, src:Float32Array ) : void {
            context.call("Atan_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfsincos( dstsin:Float32Array, dstcos:Float32Array, src:Float32Array ) : void {
            context.call("SinCos_32f", dstsin.data, dstcos.data, src.data, dstsin.offset, dstcos.offset, src.offset, dstsin.length, dstcos.length, src.length);
        }
        
        public static function vfatan2( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Atan2_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfexp( dst:Float32Array, src:Float32Array ) : void {
            context.call("Exp_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vflog( dst:Float32Array, src:Float32Array ) : void {
            context.call("Log_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vflog10( dst:Float32Array, src:Float32Array ) : void {
            context.call("Log10_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfpow( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Pow_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfpowc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("PowC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfsqrt( dst:Float32Array, src:Float32Array ) : void {
            context.call("Sqrt_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfcbrt( dst:Float32Array, src:Float32Array ) : void {
            context.call("Cbrt_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfceil( dst:Float32Array, src:Float32Array ) : void {
            context.call("Ceil_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vffloor( dst:Float32Array, src:Float32Array ) : void {
            context.call("Floor_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfabs( dst:Float32Array, src:Float32Array ) : void {
            context.call("Abs_32f", dst.data, src.data, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vfmod( dst:Float32Array, src1:Float32Array, src2:Float32Array ) : void {
            context.call("Mod_32f", dst.data, src1.data, src2.data, dst.offset, src1.offset, src2.offset, dst.length, src1.length, src2.length);
        }
        
        public static function vfmodc( dst:Float32Array, src:Float32Array, val:Number ) : void {
            context.call("ModC_32f", dst.data, src.data, val, dst.offset, src.offset, dst.length, src.length);
        }
        
        public static function vffma( dst:Float32Array, src1:Float32Array, src2:Float32Array, src3:Float32Array ) : void {
            context.call("FMA_32f", dst.data, src1.data, src2.data, src3.data, dst.offset, src1.offset, src2.offset, src3.offset, dst.length, src1.length, src2.length, src3.length);
        }
        */
        
    }
    
}