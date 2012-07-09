package com.strix.lab.performance {
    
    public class ArrayRange {
        
        protected var
            _start  : uint,
            _length : uint,
            array   : NumericArray;
        
        public function ArrayRange( array:NumericArray, start:uint, length:uint ) {
            if( start >= array.length || start+length >= array.length ) {
                throw new Error("Attempted to create an ArrayRange outside of the array");
            }
            
            _start = start;
            _length = length;
        }
        
        public function get start() : uint {
            return start;
        }
        
        public function get length() : uint {
            return _length;
        }
        
        
    }
    
}