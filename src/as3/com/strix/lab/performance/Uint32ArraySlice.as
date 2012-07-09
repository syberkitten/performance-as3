package com.strix.lab.performance {
    
    public interface Uint32ArraySlice {
        
        function get start()  : uint;
        function get length() : uint;
        function get array()  : Uint32Array;
        
    }
    
}