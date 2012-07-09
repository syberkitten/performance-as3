package flexUnitTests {
    
    import com.strix.lab.performance.Float32Array;
    import com.strix.lab.performance.PerformanceLibrary;
    import com.strix.lab.performance.vfadd;
    import com.strix.lab.performance.vfaddc;
    import com.strix.lab.performance.vfdiv;
    import com.strix.lab.performance.vfdivc;
    import com.strix.lab.performance.vfdivcr;
    import com.strix.lab.performance.vfmul;
    import com.strix.lab.performance.vfmulc;
    import com.strix.lab.performance.vfset;
    import com.strix.lab.performance.vfsub;
    import com.strix.lab.performance.vfsubc;
    import com.strix.lab.performance.vfsubcr;
    
    import flexunit.framework.Assert;
    
    import org.flexunit.asserts.assertTrue;
    import org.flexunit.asserts.fail;
    import org.hamcrest.assertThat;
    
    
    public class TestPerformanceLib {
        
        private var
            fr  : Number,
            fa  : Number,
            fb  : Number,
            fval   : Number,
            vfr : Float32Array,
            vfa : Float32Array,
            vfb : Float32Array,
            fdiff : Number;

        private const
            EPS : Number = 0.0001;
        
        
        [AfterClass]
        public static function tearDownAfterClass() : void {
            PerformanceLibrary.dispose();
        }
        
        [Before]
        public function setUp() : void {
            vfr = new Float32Array(4);
            vfa = new Float32Array(4);
            vfb = new Float32Array(4);
            
            fr = 0.0;
            fa = frand();
            fb = frand();
            fval = frand();

            vfset(vfr, fr);
            vfset(vfa, fa);
            vfset(vfb, fb);
        }
       
        
        private function frand() : Number {
            if( Math.random() > 0.5 ) {
                return int(Math.random()*1000);
            } else {
                return int(Math.random()*-1000);
            }
        }
        
        private function nearEquals( a:Number, b:Number, eps:Number=EPS ) : Boolean {
            return Math.abs(a-b) <= eps;
        }
        
        private function absDiff( a:Number, b:Number ) : Number {
            return Math.abs(a-b);
        }
        
        
        [Test]
        public function testAdd32f() : void {
            vfadd(vfr, vfa, vfb);             
            fr = fa + fb;
        
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testAddC32f() : void {
            vfaddc(vfr, vfa, fval);             
            fr = fa + fval;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testSub32f() : void {
            vfsub(vfr, vfa, vfb);             
            fr = fa - fb;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testSubC32f() : void {
            vfsubc(vfr, vfa, fval);             
            fr = fa - fval;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testSubCRev32f() : void {
            vfsubcr(vfr, vfa, fval);             
            fr = fval - fa;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testDiv32f() : void {
            vfdiv(vfr, vfa, vfb);             
            fr = fa / fb;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testDivC32f() : void {
            vfdivc(vfr, vfa, fval); 
            fr = fa / fval;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testDivCRev32f() : void {
            vfdivcr(vfr, vfa, fval); 
            fr = fval / fa;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testMul32f() : void {
            vfmul(vfr, vfa, vfb);             
            fr = fa * fb;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);

            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }
        
        [Test]
        public function testMulC32f() : void {
            vfmulc(vfr, vfa, fval);             
            fr = fa * fval;
            
            fdiff = Math.abs((vfr[0] as Number) - fr);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                fdiff <= EPS
            );
        }

    
    }
}