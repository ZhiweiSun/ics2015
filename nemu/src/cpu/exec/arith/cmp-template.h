#include "cpu/exec/template-start.h"

#define instr cmp
static void do_execute() {
    DATA_TYPE result = op_dest->val - op_src->val;
	if(op_dest->val < op_src->val) cpu.CF = 1; else cpu.CF = 0;
	if(MSB(op_dest->val) != MSB(op_src->val) && MSB(result) != MSB(op_dest->val))
		cpu.OF = 1; else cpu.OF = 0;

    print_asm_template2();
}
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif
make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)
#include "cpu/exec/template-end.h"