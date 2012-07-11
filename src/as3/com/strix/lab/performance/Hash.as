package com.strix.lab.performance {
    import flash.utils.ByteArray;
    
    public final class Hash {
        
        public static function wang( dst:ByteArray, src:ByteArray ) : void {
            if( dst.length % 4 != 0 || src.length % 4 != 0 )
                throw new Error("'dst' and 'src' must have a length that is a multiple of 4");
            
            PerformanceLibrary.context.call(
                "Hash_Wang_32u",
                dst,
                src,
                dst.length / 4
            );
        }
        
        public static function xxhash( src:ByteArray ) : uint {
            return(
                PerformanceLibrary.context.call(
                    "Hash_XXHFast_8u",
                    src,
                    0,
                    0,
                    src.length
                ) as uint
            );
        }
        
        public static function xxhash_strong( src:ByteArray ) : uint {
            return(
                PerformanceLibrary.context.call(
                    "Hash_XXHStrong_8u",
                    src,
                    0,
                    0,
                    src.length
                ) as uint
            );
        }
        
    }
    
}