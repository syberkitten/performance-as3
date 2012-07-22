package com.strix.lab.as3pp.matrix {
    
    import com.strix.lab.as3pp.array.ArrayUtils;
    import com.strix.lab.as3pp.array.Float32Array;
    
    
    public class Matrix44Array {
        
        public static const
            ValueElement  : uint = 0,
            ZeroElement   : uint = 1,
            NullElement   : uint = 2;
            
        public static const
            R1 : uint = 0,
            R2 : uint = 1,
            R3 : uint = 2,
            R4 : uint = 3,
            C1 : uint = 0,
            C2 : uint = 1,
            C3 : uint = 2,
            C4 : uint = 3;
    
        public var
            data : Vector.<Vector.<Float32Array>>,
            meta : Vector.<Vector.<uint>>;
        
        protected var
            _length : uint;
            
            
        public function Matrix44Array( length:uint=4 ) {
            this._length = length;
            this.data = new Vector.<Vector.<Float32Array>>(4, true);
            this.meta = new Vector.<Vector.<uint>>(4, true);
            
            for( var r : uint = R1; r <= R4; r++ ) {
                this.data[r] = new Vector.<Float32Array>(4, true);
                this.meta[r] = new Vector.<uint>(4, true);
                
                for( var c : uint = C1 ; c <= C4; c++ ) {
                    this.data[r][c] = new Float32Array(length);
                }
            }
        }
        
        public function get length() : uint {
            return _length;
        }
        
        public function reset() : void {
            ArrayUtils.set_32f(this.data[R1][C1], 0.0);
            ArrayUtils.set_32f(this.data[R1][C2], 0.0);
            ArrayUtils.set_32f(this.data[R1][C3], 0.0);
            ArrayUtils.set_32f(this.data[R1][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R2][C1], 0.0);
            ArrayUtils.set_32f(this.data[R2][C2], 0.0);
            ArrayUtils.set_32f(this.data[R2][C3], 0.0);
            ArrayUtils.set_32f(this.data[R2][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R3][C1], 0.0);
            ArrayUtils.set_32f(this.data[R3][C2], 0.0);
            ArrayUtils.set_32f(this.data[R3][C3], 0.0);
            ArrayUtils.set_32f(this.data[R3][C4], 0.0);
            
            ArrayUtils.set_32f(this.data[R4][C1], 0.0);
            ArrayUtils.set_32f(this.data[R4][C2], 0.0);
            ArrayUtils.set_32f(this.data[R4][C3], 0.0);
            ArrayUtils.set_32f(this.data[R4][C4], 0.0);
            
            meta[R1][C1] = ZeroElement;
            meta[R1][C2] = ZeroElement;
            meta[R1][C3] = ZeroElement;
            meta[R1][C4] = ZeroElement;
            
            meta[R2][C1] = ZeroElement;
            meta[R2][C2] = ZeroElement;
            meta[R2][C3] = ZeroElement;
            meta[R2][C4] = ZeroElement;
            
            meta[R3][C1] = ZeroElement;
            meta[R3][C2] = ZeroElement;
            meta[R3][C3] = ZeroElement;
            meta[R3][C4] = ZeroElement;
            
            meta[R4][C1] = ZeroElement;
            meta[R4][C2] = ZeroElement;
            meta[R4][C3] = ZeroElement;
            meta[R4][C4] = ZeroElement;
        }
        
    }
    
}