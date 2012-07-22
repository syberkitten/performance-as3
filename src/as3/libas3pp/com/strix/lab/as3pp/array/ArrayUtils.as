package com.strix.lab.as3pp.array {
    
    import com.strix.lab.as3pp.PerformancePrimitives;
    
    
    public final class ArrayUtils {
        
        /**
         * dst = src
         */
        public static function copy_32f( dst:Float32Array, src:Float32Array ) : void {
            PerformancePrimitives.context.call(
                "Copy_32f",
                dst.data, src.data,
                dst.offset, src.offset,
                dst.length
            );
        }
        
        /**
         * dst = val
         */
        public static function set_32f( dst:Float32Array, val:Number ) : void {
            PerformancePrimitives.context.call(
                "Set_32f",
                dst.data, val,
                dst.offset,
                dst.length
            );
        }
        
    }
    
}