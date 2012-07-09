package flexUnitTests {
    
    import com.strix.lab.performance.Float32Array;
    import com.strix.lab.performance.PerformanceLibrary;
    import com.strix.lab.performance.vfadd;
    import com.strix.lab.performance.vfaddc;
    import com.strix.lab.performance.vfcos;
    import com.strix.lab.performance.vfdiv;
    import com.strix.lab.performance.vfdivc;
    import com.strix.lab.performance.vfdivcr;
    import com.strix.lab.performance.vfmul;
    import com.strix.lab.performance.vfmulc;
    import com.strix.lab.performance.vfset;
    import com.strix.lab.performance.vfsin;
    import com.strix.lab.performance.vfsincos;
    import com.strix.lab.performance.vfsub;
    import com.strix.lab.performance.vfsubc;
    import com.strix.lab.performance.vfsubcr;
    import com.strix.lab.performance.vftan;
    
    import flexunit.framework.Assert;
    
    import org.flexunit.asserts.assertTrue;
    import org.flexunit.asserts.fail;
    import org.hamcrest.assertThat;
    
    
    public class TestPerformanceLib {
        
        private var
            fr    : Number,
            fa    : Number,
            fb    : Number,
            fval  : Number,
            vfr   : Float32Array,
            vfr2  : Float32Array,
            vfa   : Float32Array,
            vfb   : Float32Array;

        private const
            EPS : Number = 0.0001;
        
        
        [AfterClass]
        public static function tearDownAfterClass() : void {
            PerformanceLibrary.dispose();
        }
        
        [Before]
        public function setUp() : void {
            vfr = new Float32Array(4);
            vfr2 = new Float32Array(4);
            vfa = new Float32Array(4);
            vfb = new Float32Array(4);
            
            fr = 0.0;
            fa = frand();
            fb = frand();
            fval = frand();

            vfset(vfr, fr);
            vfset(vfr2, fr);
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
        
        
        [Test]
        public function testAdd32f() : void {
            vfadd(vfr, vfa, vfb);             
            fr = fa + fb;
        
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testAddC32f() : void {
            vfaddc(vfr, vfa, fval);             
            fr = fa + fval;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSub32f() : void {
            vfsub(vfr, vfa, vfb);             
            fr = fa - fb;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSubC32f() : void {
            vfsubc(vfr, vfa, fval);             
            fr = fa - fval;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSubCRev32f() : void {
            vfsubcr(vfr, vfa, fval);             
            fr = fval - fa;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testDiv32f() : void {
            vfdiv(vfr, vfa, vfb);             
            fr = fa / fb;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testDivC32f() : void {
            vfdivc(vfr, vfa, fval); 
            fr = fa / fval;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testDivCRev32f() : void {
            vfdivcr(vfr, vfa, fval); 
            fr = fval / fa;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testMul32f() : void {
            vfmul(vfr, vfa, vfb);             
            fr = fa * fb;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testMulC32f() : void {
            vfmulc(vfr, vfa, fval);             
            fr = fa * fval;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSin32f() : void {
            vfsin(vfr, vfa);             
            fr = Math.sin(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testCos32f() : void {
            vfcos(vfr, vfa);             
            fr = Math.cos(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSinCos32f() : void {      
            vfsincos(vfr, vfr2, vfa);
            
            fr = Math.sin(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
            
            fr = Math.cos(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr2[0] as Number, fr)
            );
        }
        
        [Test]
        public function testTan32f() : void {
            vftan(vfr, vfa);             
            fr = Math.tan(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }

    
    }
}