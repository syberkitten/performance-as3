package com.strix.lab.as3pp.error {
    
    import flash.errors.IllegalOperationError;
    
    public class AliasingError extends IllegalOperationError {
        
        public function AliasingError( message:String="", id:int=0 ) {
            super(message, id);
        }
        
    }
    
}