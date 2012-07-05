package com.strix.lab.performance {
    
    import flash.utils.ByteArray;
    import flash.utils.Endian;
    import flash.utils.Proxy;
    import flash.utils.flash_proxy;
    
    
    public class Uint32Array extends Proxy {
        
        private var
            _length : uint,
            _offset : uint;
        
        public var
            data   : ByteArray;
            
        public function Uint32Array( length : int ) {
            this.data = new ByteArray;
            this.data.endian = Endian.LITTLE_ENDIAN
            this.length = length;
        }
        
        public function get length() : uint {
            return _length;
        }
        
        public function set length( value:uint ) : void {
            if( value % 4 != 0 ) {
                throw new Error("'length' must be a multiple of 4");
            }
            
            if( value == 0 ) {
                throw new Error("'length' cannot be 0");
            }
            
            var alignment : uint = getMemoryAddress(data) % 16;
            
            if( alignment == 0 ) {
                _offset = 0;
                data.length = value * 4;
            } else {
                _offset = 16-alignment;
                data.length = value*4 + _offset;
            }
            
        }
        
        public function get offset() : uint {
            return _offset;
        }
        
        flash_proxy override function getProperty( index:* ) : * {
            data.position = offset + uint(index)*4;
            return data.readUnsignedInt();
        }
        
        flash_proxy override function setProperty( index:*, value:* ) : void {
            data.position = offset + uint(index)*4;
            data.writeUnsignedInt(uint(value));
        }
        
    }
}