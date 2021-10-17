/*
 *  ATICard.h
 *  FakeSMCRadeon
 *
 *  Originally created by Slice on 24.07.10.
 *  Copyright 2010 Applelife.ru. All rights reserved.
 *
 */

#ifndef _ATICARD_H
#define _ATICARD_H

#include <IOKit/IOService.h>
#include <IOKit/pci/IOPCIDevice.h>
#include "radeon_chipsets.h"

enum TempFamilies {
    R5xx,
    R6xx,
    R7xx,
    R8xx,
    R9xx,
    RCIx,
    RAIx,
    RVEx,
};

class ATICard : public OSObject {
    OSDeclareDefaultStructors(ATICard)

public:
    UInt32          chipID;
    UInt16          family;
    IOPCIDevice *   VCard;
    RADEONCardInfo* rinfo;
    int             tempFamily;
    
private:
    volatile UInt8* mmio_base;
    IOMemoryMap *   mmio;
    UInt32          Caps;
    UInt32          tReg;
    int             card_number;
    
    bool            getRadeonInfo();
    
public:
  UInt32      read32(UInt32 reg);
  void        write32(UInt32 reg, UInt32 val);
  UInt32      read_ind(UInt32 reg);
  UInt32      read_smc(UInt32 reg);

  bool        initialize(void);
  IOReturn    R6xxTemperatureSensor(UInt16* data);
  IOReturn    R7xxTemperatureSensor(UInt16* data);
  IOReturn    EverTemperatureSensor(UInt16* data);
  IOReturn    TahitiTemperatureSensor(UInt16* data);
  IOReturn    HawaiiTemperatureSensor(UInt16* data);
  IOReturn    ArcticTemperatureSensor(UInt16* data);
  IOReturn    VegaTemperatureSensor(UInt16* data);
};


#endif
