package com.strix.lab.performance {
    
    public interface Float32ArraySlice {
        
        function get start() : uint;
        function get length() : uint;
        function get array() : Float32Array;
        
    }
    
}