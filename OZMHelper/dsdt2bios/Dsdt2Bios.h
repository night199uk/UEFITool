#ifndef DSDT2BIOS_H
#define DSDT2BIOS_H

#include <QByteArray>
#include <capstone.h>
#include <../basetypes.h>

#define DSDT_HEADER "DSDT"
#define UNPATCHABLE_SECTION ".ROM"

class Dsdt2Bios
{
public:
    UINT8 getDSDTFromAmi(QByteArray amiboard, UINT16 &DSDTOffset, UINT16 &DSDTSize);
    UINT8 injectDSDTIntoAmi(QByteArray amiboardbuf, QByteArray dsdtbuf, UINT16 DSDTOffsetOld, UINT16 DSDTSizeOld, QByteArray & out, UINT16 & relocPadding);

private:
    UINT64 insn_detail(csh ud, cs_mode mode, cs_insn *ins);
    UINT8 Disass(UINT8 *X86_CODE64, INT32 CodeSize, INT32 size);
};

struct platform
{
    cs_arch arch;
    cs_mode mode;
    unsigned char *code;
    size_t size;
    char *comment;
    cs_opt_type opt_type;
    cs_opt_value opt_value;
};

#endif // DSDT2BIOS_H