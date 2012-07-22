package com.strix.lab.as3pp.matrix {
    
    import com.strix.lab.as3pp.PerformancePrimitives;
    import com.strix.lab.as3pp.array.ArrayMath;
    import com.strix.lab.as3pp.array.ArrayUtils;
    import com.strix.lab.as3pp.array.Float32Array;
    import com.strix.lab.as3pp.error.AliasingError;
    import com.strix.lab.as3pp.error.MatrixAliasingError;
    import com.strix.lab.as3pp.vector.Vector3DArray;
    
    import flash.errors.IllegalOperationError;
    import flash.geom.Matrix;
    import flash.geom.Matrix3D;

    
    public final class MatrixMath {
        
        private static const
            TEMP_SIZE : uint = 2048;
            
        private static const
            ValueElement : uint = 0,
            ZeroElement  : uint = 1,
            NullElement  : uint = 2;
            
        private static const
            R1 : uint = 0,
            R2 : uint = 1,
            R3 : uint = 2,
            R4 : uint = 3,
            C1 : uint = 0,
            C2 : uint = 1,
            C3 : uint = 2,
            C4 : uint = 3;
            
        private static var
            t : Float32Array;
        
        {
            t = new Float32Array(TEMP_SIZE);
        }
        
        private static function assertNoAliasing( m1:Matrix44Array, m2:Matrix44Array ) : void {
            for( var m1r : uint = 0; m1r < 4; m1r++ ) {
                for( var m1c : uint = 0; m1c < 4; m1c++ ) {
                    for( var m2r : uint = 0; m2r < 4; m2r++ ) {
                        for( var m2c : uint = 0; m2c < 4; m2c++ ) {
                            if( m1.data[m1r][m1c] === m2.data[m2r][m2c] )
                                throw new MatrixAliasingError(
                                    "matrix1", m1r, m1c,
                                    "matrix2", m2r, m2c
                                );
                        }
                    }
                } 
            }
        }
        
        public static function mul_44( dst:Matrix44Array, src1:Matrix44Array, src2:Matrix44Array ) : void {
            if( PerformancePrimitives.debugMode ) {
                if( dst === src1 || dst === src2 ) {
                    throw new AliasingError("Aliasing is not allowed. DST, SRC1 and SRC2 must be unique");
                }
                
                if( src1 === src2 ) {
                    throw new AliasingError("Aliasing is not allowed. SRC1 and SRC2 must be unqiue");
                }
                
                try {
                    assertNoAliasing(dst, src1);
                } catch( e:MatrixAliasingError ) {
                    throw new MatrixAliasingError(
                        "DST", e.matrix1Row, e.matrix1Col,
                        "SRC1", e.matrix2Row, e.matrix2Col
                    );
                }
                
                try {
                    assertNoAliasing(dst, src2);
                } catch( e:MatrixAliasingError ) {
                    throw new MatrixAliasingError(
                        "DST", e.matrix1Row, e.matrix1Col,
                        "SRC2", e.matrix2Row, e.matrix2Col
                    );
                }
                
                try {
                    assertNoAliasing(src1, src2);
                } catch( e:MatrixAliasingError ) {
                    throw new MatrixAliasingError(
                        "SRC1", e.matrix1Row, e.matrix1Col,
                        "SRC2", e.matrix2Row, e.matrix2Col
                    );
                }
            }
            
            if( PerformancePrimitives.debugMode ) {
                if( dst.length != src1.length || dst.length != src2.length ) {
                    throw new IllegalOperationError(
                        "Matrices must be of the same length"
                    );
                }
            }
            
            var i : uint, j : uint, k : uint,
                bi : uint, bj : uint, bk : uint;
            
            t.length = dst.length;
            dst.reset();

            for( bi = 0; bi < 4; bi += 2 ) {
                for( bj = 0; bj < 4; bj += 2 ) {
                    for( bk = 0; bk < 4; bk += 2 ) {
                        for( i = bi; i < bi+2; i++ ) {
                            for( j = bj; j <  bj+2; j++ ) {
                                for( k = bk; k < bk+2; k++ ) {
                                    if( src1.meta[i][k] == ZeroElement || src2.meta[k][j] == ZeroElement ||
                                        src1.meta[i][k] == NullElement || src2.meta[k][j] == NullElement ) {
                                        continue;
                                    }
                                    
                                    ArrayMath.mul_32f(t, src1.data[i][k], src2.data[k][j]);
                                    ArrayMath.addi_32f(dst.data[i][j], t);
                                    dst.meta[i][j] = ValueElement;
                                }
                            }
                        }
                    }
                }
            }
        }
        
        public static function transform3D( dst:Vector3DArray, src1:Matrix44Array, src2:Vector3DArray ) : void {
            t.length = dst.length;
            
            ArrayMath.mul_32f(dst.x, src1.data[R1][C1], src2.x);
            ArrayMath.muladd_32f(dst.x, src1.data[R1][C2], src2.y);
            ArrayMath.muladd_32f(dst.x, src1.data[R1][C3], src2.z);
            ArrayMath.muladd_32f(dst.x, src1.data[R1][C4], src2.w);
            
            ArrayMath.mul_32f(dst.y, src1.data[R2][C1], src2.x);
            ArrayMath.muladd_32f(dst.y, src1.data[R2][C2], src2.y);
            ArrayMath.muladd_32f(dst.y, src1.data[R2][C3], src2.z);
            ArrayMath.muladd_32f(dst.y, src1.data[R2][C4], src2.w);
            
            ArrayMath.mul_32f(dst.z, src1.data[R3][C1], src2.x);
            ArrayMath.muladd_32f(dst.z, src1.data[R3][C2], src2.y);
            ArrayMath.muladd_32f(dst.z, src1.data[R3][C3], src2.z);
            ArrayMath.muladd_32f(dst.z, src1.data[R3][C4], src2.w);
            
            ArrayMath.mul_32f(dst.w, src1.data[R4][C1], src2.x);
            ArrayMath.muladd_32f(dst.w, src1.data[R4][C2], src2.y);
            ArrayMath.muladd_32f(dst.w, src1.data[R4][C3], src2.z);
            ArrayMath.muladd_32f(dst.w, src1.data[R4][C4], src2.w);
        }
        
        public static function transformC3D( dst:Vector3DArray, src1:Matrix3D, src2:Vector3DArray ) : void {
            t.length = dst.length;
            
            ArrayMath.mulc_32f(dst.x, src2.x, src1.rawData[0]);
            ArrayMath.mulc_32f(t, src2.y, src1.rawData[4]);
            ArrayMath.addi_32f(dst.x, t);
            ArrayMath.mulc_32f(t, src2.z, src1.rawData[8]);
            ArrayMath.addi_32f(dst.x, t);
            ArrayMath.mulc_32f(t, src2.w, src1.rawData[12]);
            ArrayMath.addi_32f(dst.x, t);
            
            ArrayMath.mulc_32f(dst.y, src2.x, src1.rawData[1]);
            ArrayMath.mulc_32f(t, src2.y, src1.rawData[5]);
            ArrayMath.addi_32f(dst.y, t);
            ArrayMath.mulc_32f(t, src2.z, src1.rawData[9]);
            ArrayMath.addi_32f(dst.y, t);
            ArrayMath.mulc_32f(t, src2.w, src1.rawData[13]);
            ArrayMath.addi_32f(dst.y, t);
            
            ArrayMath.mulc_32f(dst.z, src2.x, src1.rawData[2]);
            ArrayMath.mulc_32f(t, src2.y, src1.rawData[6]);
            ArrayMath.addi_32f(dst.z, t);
            ArrayMath.mulc_32f(t, src2.z, src1.rawData[10]);
            ArrayMath.addi_32f(dst.z, t);
            ArrayMath.mulc_32f(t, src2.w, src1.rawData[14]);
            ArrayMath.addi_32f(dst.z, t);
            
            ArrayMath.mulc_32f(dst.w, src2.x, src1.rawData[3]);
            ArrayMath.mulc_32f(t, src2.y, src1.rawData[7]);
            ArrayMath.addi_32f(dst.w, t);
            ArrayMath.mulc_32f(t, src2.z, src1.rawData[11]);
            ArrayMath.addi_32f(dst.w, t);
            ArrayMath.mulc_32f(t, src2.w, src1.rawData[15]);
            ArrayMath.addi_32f(dst.w, t);
        }
        
    }
    
}