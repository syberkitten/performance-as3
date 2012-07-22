package com.strix.lab.as3pp.matrix {
    
    import com.strix.lab.as3pp.array.ArrayUtils;
    import com.strix.lab.as3pp.array.Float32Array;
    
    
    public class ScalingMatrix44Array extends Matrix44Array {
        
        public function ScalingMatrix44Array( length:uint=4 ) {
            super(length);
            reset();
        }
        
        public override function reset() : void {
            ArrayUtils.set_32f(this.data[R1][C1], 1.0);
            ArrayUtils.set_32f(this.data[R1][C2], 0.0);
            ArrayUtils.set_32f(this.data[R1][C3], 0.0);
            ArrayUtils.set_32f(this.data[R1][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R2][C1], 0.0);
            ArrayUtils.set_32f(this.data[R2][C2], 1.0);
            ArrayUtils.set_32f(this.data[R2][C3], 0.0);
            ArrayUtils.set_32f(this.data[R2][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R3][C1], 0.0);
            ArrayUtils.set_32f(this.data[R3][C2], 0.0);
            ArrayUtils.set_32f(this.data[R3][C3], 1.0);
            ArrayUtils.set_32f(this.data[R3][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R4][C1], 0.0);
            ArrayUtils.set_32f(this.data[R4][C2], 0.0);
            ArrayUtils.set_32f(this.data[R4][C3], 0.0);
            ArrayUtils.set_32f(this.data[R4][C4], 1.0);
            
            meta[R1][C1] = ValueElement;
            meta[R1][C2] = ZeroElement;
            meta[R1][C3] = ZeroElement;
            meta[R1][C4] = ZeroElement;
            
            meta[R2][C1] = ZeroElement;
            meta[R2][C2] = ValueElement;
            meta[R2][C3] = ZeroElement;
            meta[R2][C4] = ZeroElement;
            
            meta[R3][C1] = ZeroElement;
            meta[R3][C2] = ZeroElement;
            meta[R3][C3] = ValueElement;
            meta[R3][C4] = ZeroElement;
            
            meta[R4][C1] = ZeroElement;
            meta[R4][C2] = ZeroElement;
            meta[R4][C3] = ZeroElement;
            meta[R4][C4] = ValueElement;
        }
        
        public function setScaling( x:Float32Array, y:Float32Array, z:Float32Array ) : void {
            this.data[R1][C1] = x;
            this.data[R2][C2] = y;
            this.data[R3][C3] = z;
        }
        
    }
    
}