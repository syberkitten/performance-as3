package com.strix.lab.performance {
    
    public interface Int32ArraySlice {
        
        function get start()  : uint;
        function get length() : uint;
        function get array()  : Int32Array;
        
    }
    
}