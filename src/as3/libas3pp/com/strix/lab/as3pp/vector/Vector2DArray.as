package com.strix.lab.as3pp.vector {
    
    import com.strix.lab.as3pp.array.Float32Array;
    
    
    public class Vector2DArray {
    
        public var
            x : Float32Array,
            y : Float32Array;
            
        private var
            _length : uint;
        
        public function Vector2DArray( length:uint ) {
            this.x = new Float32Array(length);
            this.y = new Float32Array(length);
            
            this._length = length;
        }
        
        public function get length() : uint {
            return _length;
        }

    }
    
}