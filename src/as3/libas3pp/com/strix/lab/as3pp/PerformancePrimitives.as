package com.strix.lab.as3pp {
    
    import com.strix.lab.as3pp.array.ArrayMath;
    import com.strix.lab.as3pp.array.Float32Array;
    import com.strix.lab.as3pp.array.NumericArray;
    
    import flash.errors.IllegalOperationError;
    import flash.external.ExtensionContext;
    import flash.utils.ByteArray;
    
    import flashx.textLayout.formats.Float;
    
    
    public final class PerformancePrimitives {
        
        public static var
            context   : ExtensionContext,
            debugMode : Boolean = true;
        
        private static var
            _instanceCounter  : uint,
            _deferredMode     : Boolean = false,
            deferredCalls     : Vector.<Function>,
            deferredArgs      : Vector.<Array>,
            deferredInstances : Array;
            
        public static function initialize() : void {
            context = ExtensionContext.createExtensionContext("as3pp", null);
        }
        
        public static function dispose() : void {
            context.dispose();
        }
        
        public static function getMemoryAddress( byteArray:ByteArray ) : uint {
            return context.call("GetMemoryAddress", byteArray) as uint;
        }
        
        public static function get threads() : uint {
            return context.call("GetNumThreads") as uint;
        }
        
        public static function set threads( t:uint ) : void {
            //TODO
        }
        
        public static function get uniqueInstanceID() : String {
            return "AS3PP:" + String(_instanceCounter++);
        }
        
    }
    
}