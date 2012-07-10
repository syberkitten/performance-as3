package com.strix.lab.performance {
    
    import flash.events.EventDispatcher;
    import flash.events.IEventDispatcher;
    import flash.external.ExtensionContext;
    import flash.utils.ByteArray;
    
    public class PerformanceLibrary {
        
        public static var context : ExtensionContext;
        
        {
            context = ExtensionContext.createExtensionContext("PerformanceLib", null);
        }
        
        public static function dispose() : void {
            context.dispose();
        }
        
    }
    
}