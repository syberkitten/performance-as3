package com.strix.lab.as3pp {
    
    import flash.external.ExtensionContext;
    import flash.utils.ByteArray;
    
    
    public final class PerformancePrimitives {
        
        public static var
            context : ExtensionContext;
        
            
        public static function initialize() : void {
            context = ExtensionContext.createExtensionContext("as3pp", null);
        }
        
        public static function dispose() : void {
            context.dispose();
        }
        
        
        public static function getMemoryAddress( byteArray:ByteArray ) : uint {
            return context.call("GetMemoryAddress", byteArray) as uint;
        }

    }
    
}