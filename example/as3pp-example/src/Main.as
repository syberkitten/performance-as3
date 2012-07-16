package {
    
    import com.strix.lab.as3pp.ArrayMath;
    import com.strix.lab.as3pp.Float32Array;
    import com.strix.lab.as3pp.PerformancePrimitives;
    
    import flash.display.Sprite;
    
    
    public class Main extends Sprite {
        
        public function Main() {
            PerformancePrimitives.initialize();
            
            var a : Float32Array = new Float32Array(4),
                b : Float32Array = new Float32Array(4),
                sum : Float32Array = new Float32Array(4);
            
            a[0] = 1.0; a[1] = 2.0; a[2] = 3.0; a[3] = 4.0;
            b[0] = 10.0; b[1] = 20.0; b[2] = 30.0; b[3] = 40.0;
            
            ArrayMath.add_32f(sum, a, b);
            
            trace(sum[0] as Number);
            
            PerformancePrimitives.dispose();
        }
        
    }
    
}