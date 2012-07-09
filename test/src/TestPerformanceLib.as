package flexUnitTests {
    
    import com.strix.lab.performance.Float32Array;
    import com.strix.lab.performance.PerformanceLibrary;
    import com.strix.lab.performance.vfacos;
    import com.strix.lab.performance.vfadd;
    import com.strix.lab.performance.vfaddc;
    import com.strix.lab.performance.vfasin;
    import com.strix.lab.performance.vfatan;
    import com.strix.lab.performance.vfatan2;
    import com.strix.lab.performance.vfcbrt;
    import com.strix.lab.performance.vfcos;
    import com.strix.lab.performance.vfdiv;
    import com.strix.lab.performance.vfdivc;
    import com.strix.lab.performance.vfdivcr;
    import com.strix.lab.performance.vfexp;
    import com.strix.lab.performance.vffma;
    import com.strix.lab.performance.vflog;
    import com.strix.lab.performance.vflog10;
    import com.strix.lab.performance.vfmul;
    import com.strix.lab.performance.vfmulc;
    import com.strix.lab.performance.vfpow;
    import com.strix.lab.performance.vfpowc;
    import com.strix.lab.performance.vfset;
    import com.strix.lab.performance.vfsin;
    import com.strix.lab.performance.vfsincos;
    import com.strix.lab.performance.vfsqrt;
    import com.strix.lab.performance.vfsub;
    import com.strix.lab.performance.vfsubc;
    import com.strix.lab.performance.vfsubcr;
    import com.strix.lab.performance.vftan;
    
    import flexunit.framework.Assert;
    
    import org.flexunit.asserts.assertFalse;
    import org.flexunit.asserts.assertNotNull;
    import org.flexunit.asserts.assertTrue;
    import org.flexunit.asserts.fail;
    import org.hamcrest.assertThat;
    
    
    public class TestPerformanceLib {
        
        private var
            fr    : Number,
            fa    : Number,
            fb    : Number,
            fc    : Number,
            fval  : Number,
            vfr   : Float32Array,
            vfr2  : Float32Array,
            vfa   : Float32Array,
            vfb   : Float32Array,
            vfc   : Float32Array;

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
            vfc = new Float32Array(4);
            
            fr = 0.0;
            fa = frand();
            fb = frand();
            fc = frand();
            fval = frand();

            vfset(vfr, fr);
            vfset(vfr2, fr);
            vfset(vfa, fa);
            vfset(vfb, fb);
            vfset(vfc, fc);
        }
       
        
        private function frand( positiveOnly:Boolean=false ) : Number {
            if( Math.random() > 0.5 || positiveOnly ) {
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
        
        [Test]
        public function testAsin32f() : void {
            fa = 0.1234;
            vfset(vfa, fa);
            vfasin(vfr, vfa);             
            fr = Math.asin(fa);

            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testAcos32f() : void {
            fa = 0.1234;
            vfset(vfa, fa);
            vfacos(vfr, vfa);             
            fr = Math.acos(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testAtan32f() : void {
            fa = 0.1234;
            vfset(vfa, fa);
            vfatan(vfr, vfa);             
            fr = Math.atan(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testAtan232f() : void {
            fa = 0.1234;
            fb = 0.2345;
            vfset(vfa, fa);
            vfset(vfb, fb);
            vfatan2(vfr, vfa, vfb)             
            fr = Math.atan2(fa, fb);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testExp32f() : void {
            fa = 1.2345;
            vfset(vfa, fa);
            vfexp(vfr, vfa);             
            fr = Math.exp(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testLog32f() : void {
            fa = frand(true);
            vfset(vfa, fa);
            vflog(vfr, vfa);             
            fr = Math.log(fa);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testLog1032f() : void {
            fa = frand(true);
            vfset(vfa, fa);
            vflog10(vfr, vfa);             
            fr = Math.log(fa)*Math.LOG10E;
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testPow32f() : void {
            fa = 1.234;
            fb = 2.456;
            vfset(vfa, fa);
            vfset(vfb, fb);
            vfpow(vfr, vfa, vfb);             
            fr = Math.pow(fa, fb);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testPowC32f() : void {
            fa = 1.234;
            fval = 2.456;
            vfset(vfa, fa);
            vfpowc(vfr, vfa, fval);             
            fr = Math.pow(fa, fval);
            
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testSqrt32f() : void {
            fa = frand(true);
            vfset(vfa, fa);
            vfsqrt(vfr, vfa);             
            fr = Math.sqrt(fa);
           
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fr)
            );
        }
        
        [Test]
        public function testCbrt32f() : void {
            fa = frand(true);
            vfset(vfa, fa);
            vfcbrt(vfr, vfa);             
            
            assertFalse(
                vfr[0] as Number == 0.0
            );
            
            assertFalse(
                isNaN(vfr[0] as Number)
            );
            
            assertFalse(
                vfr[0] as Number == Infinity
            );
        }
        
        [Test]
        public function testFMA32f() : void {
            vffma(vfr, vfa, vfb, vfc);             
          
            assertTrue(
                "Error exceeded absolute tolerance",
                nearEquals(vfr[0] as Number, fa*fb + fc)
            );
        }

    }
    
}