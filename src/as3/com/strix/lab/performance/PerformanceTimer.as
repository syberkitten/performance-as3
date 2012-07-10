package com.strix.lab.performance {
    
    public final class PerformanceTimer {
        
        private static var
            instance : PerformanceTimer,
            token    : Object = {};
        
            
        public function PerformanceTimer( token:Object=null ) {
            if( token !== PerformanceTimer.token )
                throw new Error("Direct instantiation of PerformanceTimer is not allowed. Please use PerformanceTimer.getInstance()");
        }
            
        public static function getInstance() : PerformanceTimer {
            if( PerformanceTimer.instance == null ) {
                PerformanceTimer.instance = new PerformanceTimer(PerformanceTimer.token);
            }
            
            PerformanceTimer.instance.refresh();
            
            return PerformanceTimer.instance;
        }
        
        
        public function refresh() : void {
            PerformanceLibrary.context.call("TimerRefreshFrequency");
        }
        
        public function start() : void {
            PerformanceLibrary.context.call("TimerStart");
        }
        
        public function tick() : Number {
            return PerformanceLibrary.context.call("TimerTick") as Number;
        }
        
    }
    
}