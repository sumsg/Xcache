#ifndef X_CACHE_H_
#define X_CACHE_H_
#include <Arduino.h>
#include <EEPROM.h>

// Specifier  CommonEquivalent   Signing    Bits    Bytes    Minimum Value               Maximum Value               Format
// int8_t     signed char        Signed     8       1        -128                        127                         %c
// uint8_t    unsigned char      Unsigned   8       1        0                           255                         %c
// int16_t    short              Signed     16      2        -32,768                     32,767                      %d
// uint16_t   unsigned short     Unsigned   16      2        0                           65,535                      %u
// int32_t    int                Signed     32      4        -2,147,483,648              2,147,483,647               %ld
// uint32_t   unsigned int       Unsigned   32      4        0                           4,294,967,295               %lu
// int64_t    long long          Signed     64      8        -9,223,372,036,854,775,808  9,223,372,036,854,775,807   %lld(%l64d)
// uint64_t   unsigned long long Unsigned   64      8        0                           18,446,744,073,709,551,615  %llu(%l64u)

class Xcache
{
protected:
  int xsize = 128;
  union lInt16
  {
    int16_t s1;
    byte s2[2];
  };
  union lUInt16
  {
    uint16_t s1;
    byte s2[2];
  };
  union lUInt32
  {
    uint32_t s1;
    byte s2[4];
  };
  union lInt32
  {
    int32_t s1;
    byte s2[4];
  };
  union lUInt64
  {
    uint64_t s1;
    byte s2[8];
  };
  union lInt64
  {
    int64_t s1;
    byte s2[8];
  };

public:
  //size 0~4095
  void begin(size_t size = 128)
  {
    xsize = size;
    EEPROM.begin(size);
  };
  bool setInt(int address, int8_t val)
  {
    EEPROM.write(address, val);
    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, uint8_t val)
  {
    EEPROM.write(address, val);
    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, int16_t val)
  {
    lInt16 logt;
    logt.s1 = val;
    for (size_t i = 0; i < 2; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }
    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, uint16_t val)
  {
    lUInt16 logt;
    logt.s1 = val;
    for (int i = 0; i < 2; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }
    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, int32_t val)
  {
    lInt32 logt;
    logt.s1 = val;
    for (size_t i = 0; i < 4; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }

    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, uint32_t val)
  {
    lUInt32 logt;
    logt.s1 = val;
    for (size_t i = 0; i < 4; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }

    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, int64_t val)
  {
    lInt64 logt;
    logt.s1 = val;
    for (size_t i = 0; i < 8; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }

    return EEPROM.commit() ? true : false;
  };
  bool setInt(int address, uint64_t val)
  {
    lUInt64 logt;
    logt.s1 = val;
    for (size_t i = 0; i < 8; i++)
    {
      EEPROM.write(address + i, logt.s2[i]);
    }
    return EEPROM.commit() ? true : false;
  };

  int8_t getInt(int address, int8_t num = (int8_t)0)
  {
    int8_t value = EEPROM.read(address);
    return value;
  };
  uint8_t getInt(int address, uint8_t num = (uint8_t)0)
  {
    uint8_t value = EEPROM.read(address);
    return value;
  };
  int16_t getInt(int address, int16_t num = (int16_t)0)
  {
    lInt16 logt;
    for (size_t i = 0; i < 2; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  uint16_t getInt(int address, uint16_t num = (uint16_t)0)
  {
    lUInt16 logt;
    for (size_t i = 0; i < 2; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  int32_t getInt(int address, int32_t num = (int32_t)0)
  {
    lInt32 logt;
    for (size_t i = 0; i < 2; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  uint32_t getInt(int address, uint32_t num = (uint32_t)0)
  {
    lUInt32 logt;
    for (size_t i = 0; i < 4; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  int64_t getInt(int address, int64_t num = (int64_t)0)
  {
    lInt64 logt;
    for (size_t i = 0; i < 2; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  uint64_t getInt(int address, uint64_t num = (uint64_t)0)
  {
    lUInt64 logt;
    for (size_t i = 0; i < 4; i++)
    {
      logt.s2[i] = EEPROM.read(address + i);
    }
    return logt.s1;
  };
  bool clear()
  {
    for (int i = 0; i < xsize; i++)
    {
      EEPROM.write(i, 0);
    }
    return EEPROM.end() ? true : false;
  };
  bool remove(int address)
  {
    EEPROM.write(address, 0);
    return EEPROM.end() ? true : false;
  };
  //len:字符串长度，start：起始位
  String getString(int len, int start)
  {
    String data = "";
    for (int i = 0; i < len; i++)
    {
      data += char(EEPROM.read(start + i));
    }

    return data;
  }
  //len:字符串长度，start：起始位，val：保存的字符串
  bool setString(int len, int start, String val)
  {
    EEPROM.write(len, val.length());
    for (size_t i = 0; i < val.length(); i++)
    {
      EEPROM.write(start + i, val[i]);
    }

    return EEPROM.commit() ? true : false;
  }
};
extern Xcache xcache;
#endif