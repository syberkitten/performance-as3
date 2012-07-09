package com.strix.lab.performance {
    
    public class Int32ArrayRange implements Int32ArraySlice {
        
        public static const
            UNTIL_END : int = -1;
        
        protected var
            _start  : uint,
            _length : uint,
            _array  : Int32Array;
        
        public function Int32ArrayRange( array:Int32Array, start:uint=0, length:int=UNTIL_END ) {
            if( length == UNTIL_END ) {
                length = array.length-start;
            } else if( length < 1 ) {
                throw new Error("'length' must be at least 1");
            }
            
            if( start >= array.length || start+length > array.length ) {
                throw new Error("Attempted to create an ArrayRange outside of the array");
            }
            
            _start = start;
            _length = length;
            _array = array;
        }
        
        public function get start() : uint {
            return _start;
        }
        
        public function get length() : uint {
            return _length;
        }
        
        public function get array() : Int32Array {
            return _array;
        }
        
    }
    
}