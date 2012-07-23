package com.strix.lab.as3pp.matrix {
    
    import com.strix.lab.as3pp.array.ArrayMath;
    import com.strix.lab.as3pp.array.ArrayUtils;
    import com.strix.lab.as3pp.array.Float32Array;
    
    import flash.geom.Matrix3D;
    
    
    public class RotationYMatrix3DArray extends Matrix3DArray {
        
        public function RotationYMatrix3DArray( length:uint=4 ) {
            this.data[R1][C1] = new Float32Array(length);
            this.data[R1][C4] = new Float32Array(length);
            this.data[R2][C2] = new Float32Array(length);
            this.data[R3][C2] = new Float32Array(length);
            this.data[R3][C4] = new Float32Array(length);
            this.data[R4][C4] = new Float32Array(length);
            
            this.meta = new Vector.<Vector.<uint>>(4, true);
            this.meta[R1] = new Vector.<uint>(4, true);
            this.meta[R2] = new Vector.<uint>(4, true);
            this.meta[R3] = new Vector.<uint>(4, true);
            this.meta[R4] = new Vector.<uint>(4, true);
            
            reset();
        }
        
        public override function reset() : void {
            ArrayUtils.set_32f(this.data[R1][C1], 1.0);    
            ArrayUtils.set_32f(this.data[R1][C4], 0.0);
            ArrayUtils.set_32f(this.data[R2][C2], 1.0);
            ArrayUtils.set_32f(this.data[R3][C2], 0.0);
            ArrayUtils.set_32f(this.data[R3][C3], 1.0);
            ArrayUtils.set_32f(this.data[R3][C4], 0.0);
            ArrayUtils.set_32f(this.data[R4][C4], 1.0);
            
            meta[R1][C1] = ValueElement;
            meta[R1][C2] = NullElement;
            meta[R1][C3] = ValueElement;
            meta[R1][C4] = NullElement;
            
            meta[R2][C1] = NullElement;
            meta[R2][C2] = ValueElement;
            meta[R2][C3] = NullElement;
            meta[R2][C4] = NullElement;
            
            meta[R3][C1] = ValueElement;
            meta[R3][C2] = NullElement;
            meta[R3][C3] = ValueElement;
            meta[R3][C4] = NullElement;
            
            meta[R4][C1] = NullElement;
            meta[R4][C2] = NullElement;
            meta[R4][C3] = NullElement;
            meta[R4][C4] = ValueElement;
        }
        
        public function setRotationY( y:Float32Array ) : void {
            ArrayMath.cos_32f(this.data[R1][C1], y);
            ArrayUtils.copy_32f(this.data[R3][C3], this.data[R1][C1]);
            ArrayMath.sin_32f(this.data[R3][C1], y);
            ArrayMath.subcr_32f(this.data[R1][C3], this.data[R3][C1], 0);
        }
        
    }
    
}