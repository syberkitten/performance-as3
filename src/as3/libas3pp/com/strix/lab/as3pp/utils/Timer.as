package com.strix.lab.as3pp.utils {
    
    import com.strix.lab.as3pp.PerformancePrimitives;
    
    
    public final class Timer {
        
        private static var
            instance : Timer,
            token    : Object = {};
        
            
        public function Timer( token:Object=null ) {
            if( token !== Timer.token )
                throw new Error("Direct instantiation of Timer is not allowed. Please use Timer.getInstance()");
        }
            
        public static function getInstance() : Timer {
            if( Timer.instance == null ) {
                Timer.instance = new Timer(Timer.token);
            }
            
            Timer.instance.refresh();
            
            return Timer.instance;
        }
        
        
        public function refresh() : void {
            PerformancePrimitives.context.call("Timer_Refresh");
        }
        
        public function start() : void {
            PerformancePrimitives.context.call("Timer_Start");
        }
        
        public function tick() : Number {
            return PerformancePrimitives.context.call("Timer_Tick") as Number;
        }
        
    }
    
}