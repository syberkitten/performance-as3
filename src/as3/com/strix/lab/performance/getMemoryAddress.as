package com.strix.lab.performance {
    
    import flash.utils.ByteArray;
    
    
    public function getMemoryAddress( byteArray:ByteArray ) : uint {
        return PerformanceLibrary.context.call("GetMemoryAddress", byteArray) as uint;
    }
    
}