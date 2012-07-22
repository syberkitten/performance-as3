package com.strix.lab.as3pp.vector {
    
    import com.strix.lab.as3pp.array.Float32Array;
    
    
    public class Vector3DArray {
    
        public var
            x : Float32Array,
            y : Float32Array,
            z : Float32Array,
            w : Float32Array;
            
        private var
            _length : uint;
        
            
        public function Vector3DArray( length:uint ) {
            this.x = new Float32Array(length);
            this.y = new Float32Array(length);
            this.z = new Float32Array(length);
            this.w = new Float32Array(length);
            
            this._length = length;
        }
        
        
        public function get length() : uint {
            return _length;
        }
        
    }
    
}