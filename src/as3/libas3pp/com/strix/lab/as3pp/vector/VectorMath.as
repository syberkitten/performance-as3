package com.strix.lab.as3pp.vector {
    
    import flash.errors.IllegalOperationError;
    import com.strix.lab.as3pp.array.ArrayMath;
    import com.strix.lab.as3pp.array.ArrayUtils;
    import com.strix.lab.as3pp.array.Float32Array;
    

    public final class VectorMath {
        
        public static const
            //Come up with a more elegant solution that we can control at runtime
            TEMP_SIZE : uint = 2048;
            
        private static var
            t : Float32Array;
            
        {
            t = new Float32Array(TEMP_SIZE);
        }
            
        public static function add3D( dst:Vector3DArray, src1:Vector3DArray, src2:Vector3DArray ) : void {
            ArrayMath.add_32f(dst.x, src1.x, src2.x);
            ArrayMath.add_32f(dst.y, src1.y, src2.y);
            ArrayMath.add_32f(dst.z, src1.z, src2.z);
        }
        
        public static function add2D( dst:Vector2DArray, src1:Vector2DArray, src2:Vector2DArray ) : void {
            ArrayMath.add_32f(dst.x, src1.x, src2.x);
            ArrayMath.add_32f(dst.y, src1.y, src2.y);
        }
        
        public static function subtract3D( dst:Vector3DArray, src1:Vector3DArray, src2:Vector3DArray ) : void {
            ArrayMath.sub_32f(dst.x, src1.x, src2.x);
            ArrayMath.sub_32f(dst.y, src1.y, src2.y);
            ArrayMath.sub_32f(dst.z, src1.z, src2.z);
        }
        
        public static function subtract2D( dst:Vector2DArray, src1:Vector2DArray, src2:Vector2DArray ) : void {
            ArrayMath.sub_32f(dst.x, src1.x, src2.x);
            ArrayMath.sub_32f(dst.y, src1.y, src2.y);
        }

        public static function dotProduct3D( dst:Float32Array, src1:Vector3DArray, src2:Vector3DArray ) : void {
            t.length = dst.length;
            
            //Candidates for MulAdd
            //dst = x1*x2
            ArrayMath.mul_32f(dst, src1.x, src2.x);
            //t = y1*y2
            ArrayMath.mul_32f(t, src1.y, src2.y);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
            //t = z1*z2
            ArrayMath.mul_32f(t, src1.z, src2.z);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
        }

        public static function dotProduct2D( dst:Float32Array, src1:Vector2DArray, src2:Vector2DArray ) : void {
            t.length = dst.length;
            
            //Candidates for MulAdd
            //dst = x1*x2
            ArrayMath.mul_32f(dst, src1.x, src2.x);
            //t = y1*y2
            ArrayMath.mul_32f(t, src1.y, src2.y);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
        }
        
        public static function crossProduct3D( dst:Vector3DArray, src1:Vector3DArray, src2:Vector3DArray ) : void {
            t.length = dst.length;

            ArrayMath.mul_32f(dst.x, src1.y, src2.z);
            ArrayMath.mul_32f(t, src2.y, src1.z);
            ArrayMath.sub_32f(dst.x, dst.x, t);
           
            ArrayMath.mul_32f(dst.y, src1.z, src2.x);
            ArrayMath.mul_32f(t, src2.z, src1.x);
            ArrayMath.sub_32f(dst.y, dst.y, t);
            
            ArrayMath.mul_32f(dst.z, src1.x, src2.y);
            ArrayMath.mul_32f(t, src2.x, src1.y);
            ArrayMath.sub_32f(dst.z, dst.z, t);
        }
        
        public static function crossProduct2D( dst:Float32Array, src1:Vector2DArray, src2:Vector2DArray ) : void {
            t.length = dst.length;
            
            ArrayMath.mul_32f(dst, src1.x, src2.y);
            ArrayMath.mul_32f(t, src1.y, src2.x);
            ArrayMath.sub_32f(dst, dst, t);
        }
        
        public static function normalize3D( dst:Vector3DArray, src:Vector3DArray ) : void {
            t.length = dst.length;
            
            ArrayUtils.copy_32f(t, src.x);
            ArrayMath.maxv_32f(t, src.y);
            ArrayMath.maxv_32f(t, src.z);
            
            ArrayMath.div_32f(dst.x, src.x, t);
            ArrayMath.div_32f(dst.y, src.y, t);
            ArrayMath.div_32f(dst.z, src.z, t);
        }
        
        public static function normalize2D( dst:Vector2DArray, src:Vector2DArray ) : void {
            t.length = dst.length;
            
            ArrayUtils.copy_32f(t, src.x);
            ArrayMath.maxv_32f(t, src.y);
            ArrayMath.div_32f(dst.x, src.x, t);
            ArrayMath.div_32f(dst.y, src.y, t);
        }
        
        
        public static function project3D( dst:Vector3DArray, src:Vector3DArray ) : void {
            ArrayMath.div_32f(dst.x, src.x, src.w);
            ArrayMath.div_32f(dst.y, src.y, src.w);
            ArrayMath.div_32f(dst.z, src.z, src.w);
        }
        
        public static function scale3D( dst:Vector3DArray, src:Vector3DArray, factor:Float32Array ) : void {
            ArrayMath.mul_32f(dst.x, src.x, factor);
            ArrayMath.mul_32f(dst.y, src.y, factor);
            ArrayMath.mul_32f(dst.z, src.z, factor);
        }
        
        public static function scaleBy3D( dst:Vector3DArray, src:Vector3DArray, factor:Number ) : void {
            ArrayMath.mulc_32f(dst.x, src.x, factor);
            ArrayMath.mulc_32f(dst.y, src.y, factor);
            ArrayMath.mulc_32f(dst.z, src.z, factor);
        }
        
        public static function scale2D( dst:Vector2DArray, src:Vector2DArray, factor:Float32Array ) : void {
            ArrayMath.mul_32f(dst.x, src.x, factor);
            ArrayMath.mul_32f(dst.y, src.y, factor);
        }
        
        public static function scaleBy2D( dst:Vector2DArray, src:Vector2DArray, factor:Number ) : void {
            ArrayMath.mulc_32f(dst.x, src.x, factor);
            ArrayMath.mulc_32f(dst.y, src.y, factor);
        }
        
        public static function length3D( dst:Float32Array, src:Vector3DArray ) : void {
            t.length = dst.length;

            //Candidates for MulAdd
            //dst = x*x
            ArrayMath.mul_32f(dst, src.x, src.x);
            //t = y*y
            ArrayMath.mul_32f(t, src.y, src.y);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
            //t = z*z
            ArrayMath.mul_32f(t, src.z, src.z);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
            //dst = sqrt(dst);
            ArrayMath.sqrt_32f(dst, dst);
        }
        
        public static function length2D( dst:Float32Array, src:Vector3DArray ) : void {
            t.length = dst.length;
            
            //Candidates for MulAdd
            //dst = x*x
            ArrayMath.mul_32f(dst, src.x, src.x);
            //t = y*y
            ArrayMath.mul_32f(t, src.y, src.y);
            //dst = dst + t
            ArrayMath.add_32f(dst, dst, t);
            //dst = sqrt(dst);
            ArrayMath.sqrt_32f(dst, dst);
        }
        
    }
    
}