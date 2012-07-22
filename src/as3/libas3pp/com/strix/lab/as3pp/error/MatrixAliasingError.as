package com.strix.lab.as3pp.error {
    
    public class MatrixAliasingError extends AliasingError {
        
        public var
            matrix1    : String,
            matrix1Row : uint,
            matrix1Col : uint,
            matrix2    : String,
            matrix2Row : uint,
            matrix2Col : uint;
        
        public function MatrixAliasingError(
            matrix1:String, matrix1Row:uint, matrix1Col:uint,
            matrix2:String, matrix2Row:uint, matrix2Col:uint,
            message:String="", id:int=0 ) {
            
            this.matrix1 = matrix1;
            this.matrix1Row = matrix1Row;
            this.matrix1Col = matrix1Col;
            
            this.matrix2 = matrix2;
            this.matrix2Row = matrix2Row;
            this.matrix2Col = matrix2Col;
            
            if( message == "" )
                message = 
                    "Aliasing error. Matrix element " +
                    matrix1 + "[" + matrix1Row + "][" + matrix1Col + "] alias of " +
                    matrix2 + "[" + matrix2Row + "][" + matrix2Col + "]";
            
            super(message, id);
        }
        
    }
    
}