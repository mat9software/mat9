#include "common/test.h"
#include "common/allocators.h"

#include "test/test_common_str.h"
#include "test/test_common_log.h"
#include "test/test_common_dyn_buf.h"

#include <stdlib.h>

static struct allocators allocator =
{
 .malloc=&malloc,
 .realloc=&realloc,
 .free=&free
};

//--------------------------------------------------------------------------------
int main() {

test_common_str_run(allocator);
test_common_log_run(allocator);
test_common_dyn_buf(allocator);

}
